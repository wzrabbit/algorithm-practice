import sys
input = sys.stdin.readline
print = sys.stdout.write


def check(r, c):
    if r < 0 or r >= row or c < 0 or c >= col:
        return True

    if board[r][c] == '.':
        board[r][c] = 'D'

    if board[r][c] == 'S':
        return False

    return True


dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
row, col = map(int, input().split())
board = []
fail = False
for _ in range(row):
    board.append(list(input().strip()))

for r_ in range(row):
    for c_ in range(col):
        if board[r_][c_] == 'W':
            for i in range(4):
                r = r_ + dr[i]
                c = c_ + dc[i]

                if not check(r, c):
                    fail = True

if fail:
    print('0')
else:
    print('1\n')
    for r in range(row):
        print(''.join(board[r]) + '\n')
