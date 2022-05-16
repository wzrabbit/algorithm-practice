n = int(input())
board = list(map(int, input().split()))
inf = 10000
dp = [inf] * n
dp[0] = 0

for i in range(n - 1):
    if dp[i] == inf:
        continue
    for j in range(i, min(i + board[i] + 1, n)):
        dp[j] = min(dp[i] + 1, dp[j])

if dp[-1] == inf:
    print(-1)
else:
    print(dp[-1])
