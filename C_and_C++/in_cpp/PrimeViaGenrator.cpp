#include <coroutine>
#include <exception>
#include <iterator>
#include <optional>
#include <utility>
template <typename T>
class Generator {
public:
    struct promise_type;
    using handle_type = std::coroutine_handle<promise_type>;

    class iterator {
    public:
        using iterator_category = std::input_iterator_tag;
        using value_type = T;
        using difference_type = std::ptrdiff_t;

        iterator() = default;
        explicit iterator(handle_type h) : coro_(h) {}

        iterator& operator++() {
            coro_.resume();
            if (coro_.promise().exception_) {
                std::rethrow_exception(coro_.promise().exception_);
            }
            return *this;
        }

        const T& operator*() const {
            return *coro_.promise().current_value_;
        }

        bool operator==(std::default_sentinel_t) const {
            return !coro_ || coro_.done();
        }

    private:
        handle_type coro_ = nullptr;
    };

    struct promise_type {
        std::optional<T> current_value_;
        std::exception_ptr exception_;

        auto get_return_object() {
            return Generator{handle_type::from_promise(*this)};
        }

        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }

        std::suspend_always yield_value(T value) noexcept {
            current_value_ = std::move(value);
            return {};
        }

        void return_void() noexcept {}

        void unhandled_exception() {
            exception_ = std::current_exception();
        }
    };

    Generator(Generator&& other) noexcept : coro_(std::exchange(other.coro_, nullptr)) {}
    Generator(const Generator&) = delete;

    ~Generator() {
        if (coro_) coro_.destroy();
    }

    iterator begin() {
        if (coro_) {
            coro_.resume();
            if (coro_.promise().exception_) {
                std::rethrow_exception(coro_.promise().exception_);
            }
        }
        return iterator{coro_};
    }

    std::default_sentinel_t end() const noexcept { return {}; }

private:
    explicit Generator(handle_type h) : coro_(h) {}
    handle_type coro_;
};
#include <iostream>

Generator<int> primes() {
    for (int n = 2; ; ++n) {
        bool prime = true;
        for (int d = 2; d * d <= n; ++d) {
            if (n % d == 0) {
                prime = false;
                break;
            }
        }
        if (prime) co_yield n;
    }
}

int main() {
    int count = 0;
    for (int p : primes()) {
        std::cout << p << '\n';
        if (++count == 10) break;
    }
}