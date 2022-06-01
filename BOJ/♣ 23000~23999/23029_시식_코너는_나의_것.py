import sys
input = sys.stdin.readline

n = int(input())
food = []
dp = [[0] * 3 for i in range(n)]

for _ in range(n):
    food.append(int(input()))
dp[0][1] = food[0]

for r in range(1, n):
    dp[r][0] = max(dp[r - 1])
    dp[r][1] = dp[r - 1][0] + food[r]
    dp[r][2] = dp[r - 1][1] + food[r] // 2

print(max(dp[n - 1]))
