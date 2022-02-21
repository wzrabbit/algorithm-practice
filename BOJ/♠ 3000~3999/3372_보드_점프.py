import sys
input = sys.stdin.readline

width = int(input())
board = []
dp = [[0 for j in range(width)] for i in range(width)]
for _ in range(width):
    board.append(list(map(int, input().split())))

dp[0][0] = 1
for r in range(width):
    for c in range(width):
        if r == width - 1 and c == width - 1:
            break
        v = board[r][c]
        if r + v < width:
            dp[r + v][c] += dp[r][c]
        if c + v < width:
            dp[r][c + v] += dp[r][c]

print(dp[-1][-1])