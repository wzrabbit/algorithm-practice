N = int(input())
INF = 1000000000

dp = [(INF, INF) for _ in range(N + 1)]
dp[0] = (0, 0)

for i in range(0, N):
    if i + 1 <= N:
        dp[i + 1] = min(dp[i + 1], (dp[i][0] + 1, dp[i][1] + 1))

    if i * 3 <= N:
        dp[i * 3] = min(dp[i * 3], (dp[i][0] + 1, dp[i][1] + 3))
    
    if i ** 2 <= N:
        dp[i ** 2] = min(dp[i ** 2], (dp[i][0] + 1, dp[i][1] + 5))

print(dp[N][0], dp[N][1])
