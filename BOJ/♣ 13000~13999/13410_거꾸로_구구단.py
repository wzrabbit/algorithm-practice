N, K = map(int, input().split())
best = 0

for i in range(K + 1):
    best = max(best, int(str(N * i)[::-1]))

print(best)
