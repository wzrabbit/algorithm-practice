import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write


def bfs(start_r, start_c):
    global section, space
    if visited[start_r][start_c] or grid[start_r][start_c] == '#':
        return

    visited[start_r][start_c] = True
    q = deque()
    q.append((start_r, start_c))
    section += 1

    while len(q) > 0:
        cur_r, cur_c = q.popleft()
        space += 1

        for i in range(4):
            r = cur_r + dr[i]
            c = cur_c + dc[i]

            if 0 <= r < R and 0 <= c < C and not visited[r][c] and grid[r][c] != '#':
                visited[r][c] = True
                q.append((r, c))


T = int(input())
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

for _ in range(T):
    R, C = map(int, input().split())
    grid = []
    visited = [[False] * C for ___ in range(R)]
    section = 0
    space = 0

    for __ in range(R):
        grid.append(list(input().strip()))

    for r in range(R):
        for c in range(C):
            bfs(r, c)

    print(f'{section} section{"s" if section != 1 else ""}, {space} space{"s" if space != 1 else ""}\n')
