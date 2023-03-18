def get_magic_number():
    magic_number = 1

    for i in range(2, 8001):
        if magic_number % i != 0:
            magic_number *= i

    return magic_number // 44100


MAGIC_NUMBER = get_magic_number()

while True:
    N = int(input().split()[0])
    if N == 0:
        break

    base_number = int(str(MAGIC_NUMBER) + '0' * (N - 3500))
    print(base_number - 1)
