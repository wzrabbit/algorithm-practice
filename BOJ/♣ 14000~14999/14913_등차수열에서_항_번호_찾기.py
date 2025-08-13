A, D, K = map(int, input().split())

if (K - A) % D == 0:
    print(abs(K - A) // D + 1)
else:
    print('X')
