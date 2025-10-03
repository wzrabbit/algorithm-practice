N, M, S = map(int, input().split())
print(min(M * S, (M + 1) * S * (100 - N) // 100))
