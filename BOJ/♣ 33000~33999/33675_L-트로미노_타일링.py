T = int(input())

for _ in range(T):
    N = int(input())

    if N % 2 == 1:
        print(0)
        continue

    print(2 ** (N // 2))
