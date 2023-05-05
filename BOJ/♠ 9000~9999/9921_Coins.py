N, C, W = map(int, input().split())
INF = 9999
dp = [[INF] * (W + 1) for _ in range(C + 1)]
dp[0][0] = 0

coins = []
for _ in range(N):
    coins.append(tuple(map(int, input().split())))

for i in range(C + 1):
    for j in range(W + 1):
        for v, w in coins:
            if i - v >= 0 and j - w >= 0 and dp[i - v][j - w] != INF:
                dp[i][j] = min(dp[i][j], dp[i - v][j - w] + 1)

print(0 if dp[C][W] == INF else dp[C][W])
