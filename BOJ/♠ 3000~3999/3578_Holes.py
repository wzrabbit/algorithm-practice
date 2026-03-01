N = int(input())

if N == 0:
    print(1)
    exit()

if N == 1:
    print(0)
    exit()

if N % 2 == 1:
    print(4, end='')

print('8' * (N // 2))
