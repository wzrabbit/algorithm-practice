import sys
from collections import deque
input = sys.stdin.readline

n = int(input())
board = []
visited = [[False] * n for i in range(n)]
dr = (0, 1)
dc = (1, 0)
for _ in range(n):
    board.append(list(map(int, input().split())))
success = False
que = deque()
que.append((0, 0))

while len(que):
    ro, co = que.popleft()
    if board[ro][co] == -1:
        success = True
        break

    for i in range(2):
        r, c = ro + dr[i] * board[ro][co], co + dc[i] * board[ro][co]
        if 0 <= r < n and 0 <= c < n and visited[r][c] == False:
            visited[r][c] = True
            que.append((r, c))

if success:
    print('HaruHaru')
else:
    print('Hing')
