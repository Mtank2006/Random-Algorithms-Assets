def generator_prime(start,end) :
    for num in range(start,end) :
        if num < 3:
            continue
        is_prime = True
        for i in range (3, int (num ** 0.5), 2) :
            if num % i == 0 :
                is_prime = False
                break
        if is_prime:
            yield num


def function_prime(start,end) :
    prime_list = []
    for num in range(start,end) :
        if num < 3:
            continue
        is_prime = True
        for i in range (3, int (num ** 0.5), 2) :
            if num % i == 0 :
                is_prime = False
                break
        if is_prime:
            prime_list.append(num)
    return prime_list


# temp = list(generator_prime(2,5000000)
temp = function_prime(2,5000000)
# print(list(generator_prime(2,5000000)))
# print(function_prime(4,5000000))