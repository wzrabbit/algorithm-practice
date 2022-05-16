coin, goal = map(int, input().split())
inf = 1000000
dp = [inf] * (goal + 1)
dp[0] = 0

for i in range(coin):
    current = int(input())
    for j in range(current, goal + 1):
        dp[j] = min(dp[j], dp[j - current] + 1)

if dp[-1] == inf:
    print(-1)
else:
    print(dp[-1])
