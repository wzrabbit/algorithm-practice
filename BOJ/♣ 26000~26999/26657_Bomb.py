import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write


def find_start():
    for h in range(H):
        for r in range(R):
            for c in range(C):
                if maze[h][r][c] == 'S':
                    return (h, r, c)


def get_bomb_count():
    que = deque()
    que.append((start_h, start_r, start_c, 0))

    while len(que) > 0:
        cur_h, cur_r, cur_c, cur_d = que.popleft()
        if visited[cur_h][cur_r][cur_c]:
            continue
        visited[cur_h][cur_r][cur_c] = True

        if maze[cur_h][cur_r][cur_c] == 'E':
            return cur_d

        for i in range(6):
            h = cur_h + dh[i]
            r = cur_r + dr[i]
            c = cur_c + dc[i]

            if 0 <= h < H and 0 <= r < R and 0 <= c < C and visited[h][r][c] == False:
                if maze[h][r][c] == '#':
                    que.append((h, r, c, cur_d + 1))
                else:
                    que.appendleft((h, r, c, cur_d))


T = int(input())
dh = (-1, 1, 0, 0, 0, 0)
dr = (0, 0, -1, 1, 0, 0)
dc = (0, 0, 0, 0, -1, 1)

for _ in range(T):
    H, R, C = map(int, input().split())
    maze = [[] for _ in range(H)]
    visited = [[[False] * C for _ in range(R)] for __ in range(H)]

    for h in range(H):
        for r in range(R):
            maze[h].append(list(input().strip()))

    start_h, start_r, start_c = find_start()
    answer = get_bomb_count()
    print(f'{answer}\n')
