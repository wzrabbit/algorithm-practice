# PyPy3 으로 제출하는 것을 추천합니다.

n, limit = map(int, input().split())
dp = [[0 for j in range(n + 1)] for i in range(limit + 1)]
INF = 1000000000

for i in range(n + 1):
    dp[1][i] = 1

for i in range(2, limit + 1):
    dp[i][0] = 1
    for j in range(1, n + 1):
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % INF

print(dp[limit][n])
