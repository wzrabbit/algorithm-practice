INF = 1000001
dp = [INF] * 1000001
start, end = map(int, input().split())
dp[start] = 0

for i in range(start + 1, end + 1):
    dp[i] = dp[i - 1] + 1
    if i % 2 == 0:
        dp[i] = min(dp[i], dp[i // 2] + 1)

print(dp[end])
