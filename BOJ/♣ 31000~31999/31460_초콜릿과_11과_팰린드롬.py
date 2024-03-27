T = int(input())

for _ in range(T):
    N = int(input())

    if N == 1:
        print(0)
    elif N % 2 == 0:
        print("1" * N)
    else:
        print("1" + "2" * (N - 2) + "1")
