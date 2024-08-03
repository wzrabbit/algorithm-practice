def is_prime(num):
    i = 2

    while i * i <= num:
        if num % i == 0:
            return False
        i += 1

    return True

before, digit = map(int, input().split())
after = before + digit * 1000000

if is_prime(before) and is_prime(after):
    print('Yes')
else:
    print('No')
