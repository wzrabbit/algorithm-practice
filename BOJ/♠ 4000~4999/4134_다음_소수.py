def is_prime(number):
    i = 2

    while i * i <= number:
        if number % i == 0:
            return False

        i += 1

    return True


T = int(input())

for _ in range(T):
    N = int(input())
    x = N

    if N <= 1:
        print(2)
        continue

    while True:
        if is_prime(x):
            print(x)
            break

        x += 1
