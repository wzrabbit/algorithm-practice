import sys
input = sys.stdin.readline

row, col = map(int, input().split(' '))
dp = [[0 for c in range(col)] for r in range(row)]
max_ = 0
board = []
empty = True

for _ in range(row):
    board.append(list(map(int, input().strip())))

dp[0] = board[0]
if 1 in dp[0]:
    empty = False
for i in range(row):
    dp[i][0] = board[i][0]
    if dp[i][0] == 1:
        empty = False

for r in range(1, row):
    for c in range(1, col):
        if board[r][c] == 0:
            dp[r][c] = 0
        else:
            dp[r][c] = min(dp[r - 1][c - 1], dp[r - 1][c], dp[r][c - 1]) + 1
            if dp[r][c] > max_:
                max_ = dp[r][c]

if max_ == 0 and empty == False:
    max_ = 1
print(max_ ** 2)
