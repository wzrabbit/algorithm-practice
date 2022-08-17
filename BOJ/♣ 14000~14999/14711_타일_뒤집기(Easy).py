import sys
print = sys.stdout.write


def push_btn(row, col):
    answer[row][col] = '#'
    for i in range(4):
        r = row + dr[i]
        c = col + dc[i]
        if 0 <= r < N and 0 <= c < N:
            board[r][c] = 1 - board[r][c]


N = int(input())
start_str = input()
board = [[0] * N for _ in range(N)]
answer = [['.'] * N for _ in range(N)]
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

for c in range(N):
    if start_str[c] == '#':
        push_btn(0, c)

for r in range(1, N):
    for c in range(N):
        if board[r - 1][c] == 1:
            push_btn(r, c)

for r in range(N):
    print(''.join(answer[r]) + '\n')
