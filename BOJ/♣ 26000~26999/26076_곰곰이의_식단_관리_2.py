from collections import deque
import sys
input = sys.stdin.readline

R, C = map(int, input().split())
dr = (-1, 1, 0, 0, -1, 1, -1, 1)
dc = (0, 0, -1, 1, -1, -1, 1, 1)
dq = []
grid = []
visited = [[False] * C for _ in range(R)]
for _ in range(R):
    grid.append(list(map(int, input().split())))

for r in range(1, R):
    if grid[r][0] == 1:
        dq.append((r, 0, 0))
    else:
        dq.append((r, 0, 1))

for c in range(1, C - 1):
    if grid[R - 1][c] == 1:
        dq.append((R - 1, c, 0))
    else:
        dq.append((R - 1, c, 1))

dq.sort(key=lambda x: x[2])
dq = deque(dq)


while len(dq) > 0:
    cur_r, cur_c, cur_d = dq.popleft()
    if visited[cur_r][cur_c]:
        continue
    visited[cur_r][cur_c] = True

    if cur_r == 0 or cur_c == C - 1:
        print(cur_d)
        break

    for i in range(8):
        r = cur_r + dr[i]
        c = cur_c + dc[i]

        if 0 <= r < R and 0 <= c < C and not visited[r][c] and [r, c] != [0, 0] and [r, c] != [R - 1, C - 1]:
            if grid[r][c] == 1:
                dq.appendleft((r, c, cur_d))
            else:
                dq.append((r, c, cur_d + 1))
