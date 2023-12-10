_, H, N = map(int, input().split())

if N % 2 == 0:
    print(H * ((N - 1) // 2))
else:
    print(H * (N - 1) * (N // 2) / N)
