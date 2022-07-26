import sys
input = sys.stdin.readline

R, C = map(int, input().split())
C += 1
solved = [False] * C
board = []
for _ in range(R):
    board.append(list(map(int, input().split())))

if board[0][0] == C - 1 or board[R - 1][0] == 0:
    print('NO')
    exit(0)

for r in range(R):
    for c in range(1, C):
        if board[r][c] == 1:
            board[r][0] -= 1
            solved[c] = True

for c in range(1, C):
    if solved[c]:
        continue

    for r in range(R):
        if board[r][c] != -1:
            break
        if board[r][0] >= 1:
            board[r][0] -= 1
            solved[c] = True
            break

if False in solved[1:]:
    print('NO')
else:
    print('YES')
