import sys
from collections import deque
input = sys.stdin.readline
debug = print
print = sys.stdout.write

grid = ''
visited = ''
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
INF = 10 ** 5


def bfs(start_R, start_C, no):
    q = deque()
    q.append((start_R, start_C, 0))

    while len(q):
        cur_r, cur_c, cur_dist = q.popleft()
        if visited[no][cur_r][cur_c] != INF:
            continue
        visited[no][cur_r][cur_c] = cur_dist

        for i in range(4):
            r = cur_r + dr[i]
            c = cur_c + dc[i]

            if 0 <= r < R and 0 <= c < C and visited[no][r][c] == INF and grid[r][c] != '*':
                if grid[r][c] == '#':
                    q.append((r, c, cur_dist + 1))
                else:
                    q.appendleft((r, c, cur_dist))


T = int(input())
for _ in range(T):
    R, C = map(int, input().split())
    R += 2
    C += 2
    visited = [[[INF] * C for _ in range(R)] for __ in range(3)]
    grid = []
    grid.append(['.'] * C)
    for _ in range(R - 2):
        grid.append(['.'] + list(input().rstrip()) + ['.'])
    grid.append(['.'] * C)

    prisoner = [(0, 0)]
    for r in range(R):
        for c in range(C):
            if grid[r][c] == '$':
                prisoner.append((r, c))

    for i in range(3):
        bfs(prisoner[i][0], prisoner[i][1], i)

    best = 10 ** 5
    for r in range(R):
        for c in range(C):
            cur = visited[0][r][c] + visited[1][r][c] + visited[2][r][c]
            if grid[r][c] == '#':
                cur -= 2
            if cur < best:
                best = cur

    print(f'{best}\n')
