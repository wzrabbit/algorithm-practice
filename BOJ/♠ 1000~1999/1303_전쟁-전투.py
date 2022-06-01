import sys
from collections import deque
input = sys.stdin.readline


def traverse(start_row, start_col, team):
    que = deque()
    power = 0
    visited[start_row][start_col] = True
    que.append((start_row, start_col))

    while len(que):
        ro, co = que.popleft()
        power += 1

        for i in range(4):
            r = ro + dr[i]
            c = co + dc[i]

            if 0 <= r < row and 0 <= c < col and visited[r][c] == False and board[r][c] == team:
                visited[r][c] = True
                que.append((r, c))

    return power ** 2


col, row = map(int, input().split())
board = []
visited = [[False] * col for i in range(row)]
white = 0
blue = 0
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
for _ in range(row):
    board.append(list(input().strip()))

for r in range(row):
    for c in range(col):
        if visited[r][c] == False:
            if board[r][c] == 'W':
                white += traverse(r, c, 'W')
            else:
                blue += traverse(r, c, 'B')

print(f'{white} {blue}')
