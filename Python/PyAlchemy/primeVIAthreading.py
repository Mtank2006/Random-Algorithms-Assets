# from concurrent.futures import ThreadPoolExecutor
from concurrent.futures import ProcessPoolExecutor

def find_primes(start, end):
    primes = []
    for num in range(start, end):
        if num < 2:
            continue
        if num == 2:
            primes.append(num)
            continue
        if num % 2 == 0:
            continue

        is_prime = True
        for i in range(3, int(num ** 0.5) + 1, 2):
            if num % i == 0:
                is_prime = False
                break

        if is_prime:
            primes.append(num)

    return primes


def threaded_primes(start, end, num_threads=4):
    chunk_size = (end - start + num_threads - 1) // num_threads

    ranges = []
    for i in range(num_threads):
        s = start + i * chunk_size
        e = min(s + chunk_size, end)
        if s < e:
            ranges.append((s, e))

    all_primes = []

    # with ThreadPoolExecutor(max_workers=num_threads) as executor:
    with ProcessPoolExecutor(max_workers=num_threads) as executor:
        futures = [executor.submit(find_primes, s, e) for s, e in ranges]

        for future in futures:
            all_primes.extend(future.result())

    return sorted(all_primes)


if __name__ == "__main__":
    primes = threaded_primes(1, 10000000, num_threads=128)
    print(primes)