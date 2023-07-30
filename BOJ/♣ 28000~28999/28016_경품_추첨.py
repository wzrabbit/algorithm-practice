import sys

input = sys.stdin.readline

R, C = map(int, input().split())
grid = []
dp = [[0] * C for _ in range(R)]

for _ in range(R):
    grid.append(list(map(int, input().split())))

for c in range(C):
    if grid[0][c] == 2:
        dp[0][c] = 2 ** (R - 1)
        break

for r in range(R - 1):
    for c in range(C):
        if grid[r + 1][c] == 1:
            left_ok = grid[r + 1][c - 1] != 1 and grid[r][c - 1] != 1
            right_ok = grid[r + 1][c + 1] != 1 and grid[r][c + 1] != 1

            if left_ok:
                dp[r + 1][c - 1] += dp[r][c] // 2

            if right_ok:
                dp[r + 1][c + 1] += dp[r][c] // 2
        else:
            dp[r + 1][c] += dp[r][c]

best_no = -1
best_prob = 0

for c in range(C):
    if dp[R - 1][c] > best_prob:
        best_no = c
        best_prob = dp[R - 1][c]

print(best_no)

for r in range(R):
    for c in range(C):
        print(dp[r][c], end=" ")
    print()
