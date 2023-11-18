N, H = map(int, input().split())
INF = 10**9
dp = [INF] * (H + 5001)
dp[0] = 0

for i in range(N):
    hay, cost = map(int, input().split())

    for j in range(hay, H + 5001):
        dp[j] = min(dp[j], dp[j - hay] + cost)

best_cost = min(dp[H:])
print(best_cost)
