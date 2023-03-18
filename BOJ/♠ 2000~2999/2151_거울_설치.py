import sys
from collections import deque
input = sys.stdin.readline

N = int(input())
grid = []
for _ in range(N):
    grid.append(list(input().strip()))
visited = [[[False] * N for _ in range(N)] for __ in range(2)]
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

start_R, start_C = '', ''
for r in range(N):
    for c in range(N):
        if grid[r][c] == '#':
            start_R, start_C = r, c
            grid[r][c] = '.'
            break
    if start_R != '':
        break

q = deque()
q.append((start_R, start_C, 0, 0))
q.append((start_R, start_C, 0, 1))

while q:
    cur_r, cur_c, cur_d, pos = q.popleft()
    if visited[pos][cur_r][cur_c]:
        continue
    visited[pos][cur_r][cur_c] = True

    if grid[cur_r][cur_c] == '#':
        print(cur_d)
        break

    if not visited[1 - pos][cur_r][cur_c] and grid[cur_r][cur_c] == '!':
        q.append((cur_r, cur_c, cur_d + 1, 1 - pos))

    for i in range(4):
        r = cur_r + dr[i]
        c = cur_c + dc[i]
        if 0 <= r < N and 0 <= c < N and not visited[pos][r][c] and grid[r][c] != '*' and pos == i // 2:
            q.appendleft((r, c, cur_d, pos))
