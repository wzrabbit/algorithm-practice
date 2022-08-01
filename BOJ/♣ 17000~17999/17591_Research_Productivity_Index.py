N = int(input())
arr = list(map(int, input().split()))
arr.sort(reverse=True)
dp = [[0] * (N + 1) for _ in range(N + 1)]
dp[0][0] = 1

for r in range(N):
    for c in range(r + 1):
        dp[r + 1][c] += dp[r][c] * (100 - arr[r]) / 100
        dp[r + 1][c + 1] += dp[r][c] * arr[r] / 100

best = 0
for r in range(1, N + 1):
    cur = 0
    for c in range(1, r + 1):
        cur += (c ** (c / r)) * dp[r][c]
    best = max(best, cur)

print(best)
