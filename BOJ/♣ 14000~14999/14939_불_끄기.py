import sys
import copy
input = sys.stdin.readline

sample_board = []
board = []
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
min_ = 101


def push_btn(row, col):
    if board[row][col] == 'O':
        board[row][col] = '#'
    else:
        board[row][col] = 'O'

    for i in range(4):
        r = row + dr[i]
        c = col + dc[i]
        if 0 <= r < 10 and 0 <= c < 10:
            if board[r][c] == 'O':
                board[r][c] = '#'
            else:
                board[r][c] = 'O'


for _ in range(10):
    sample_board.append(list(input().rstrip()))

for n in range(1024):
    bin_n = bin(n)[2:].rjust(10, '0')
    board = copy.deepcopy(sample_board)
    cnt = 0
    success = True

    for i in range(10):
        if bin_n[i] == '1':
            push_btn(0, i)
            cnt += 1

    for r in range(1, 10):
        for c in range(10):
            if board[r - 1][c] == 'O':
                push_btn(r, c)
                cnt += 1

    for r in range(10):
        for c in range(10):
            if board[r][c] == 'O':
                success = False
                break
        if not success:
            break

    if success:
        min_ = min(min_, cnt)

if min_ < 101:
    print(min_)
else:
    print(-1)
