while True:
    N = int(input())

    if N == 0:
        break

    S = N * (N + 1) // 2
    print(S * S)
