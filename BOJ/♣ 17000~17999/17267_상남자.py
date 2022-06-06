import sys
from collections import deque
input = sys.stdin.readline

dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
row, col = map(int, input().split())
left, right = map(int, input().split())
board = []
for _ in range(row):
    board.append(list(input().strip()))
visited = [[False] * col for _ in range(row)]

start_r, start_c = 0, 0
for r in range(row):
    for c in range(col):
        if board[r][c] == '2':
            start_r, start_c = r, c

que = deque()
que.append((start_r, start_c, left, right))
visited[start_r][start_c] = True
count = 0

while len(que):
    ro_, co_, l, r = que.popleft()
    count += 1

    for i in range(4):
        ro = ro_ + dr[i]
        co = co_ + dc[i]

        if (0 <= ro < row and 0 <= co < col and
                visited[ro][co] == False and board[ro][co] != '1'):
            if 0 <= i < 2:
                visited[ro][co] = True
                que.appendleft((ro, co, l, r))
            elif i == 2:
                if l >= 1:
                    visited[ro][co] = True
                    que.append((ro, co, l - 1, r))
            else:
                if r >= 1:
                    visited[ro][co] = True
                    que.append((ro, co, l, r - 1))

print(count)
