import sys
from collections import deque
row, col = list(map(int, sys.stdin.readline().split(' ')))
visited = [[[False] * col for i in range(row)] for j in range(64)]

maze = []
for _ in range(row):
    maze.append(list(map(str, sys.stdin.readline().strip())))

queue = deque([])
success = False
keys = ['a', 'b', 'c', 'd', 'e', 'f']
locks = ['A', 'B', 'C', 'D', 'E', 'F']
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

for r in range(row):
    for c in range(col):
        if maze[r][c] == '0':
            maze[r][c] = '.'
            queue.append([r, c, 0, 0])
            visited[0][r][c] = True
            break

while len(queue):
    r_, c_, d_, k_ = queue.popleft()
    if maze[r_][c_] == '1':
        print(d_)
        success = True
        break

    for i in range(4):
        r = r_ + dr[i]
        c = c_ + dc[i]
        d = d_
        k = k_

        if r >= 0 and r < row and c >= 0 and c < col:
            if visited[k][r][c] == False:
                if maze[r][c] == '.' or maze[r][c] == '1':
                    visited[k][r][c] = True
                    queue.append([r, c, d + 1, k])

                elif maze[r][c] in keys:
                    key = 0
                    for i in range(6):
                        if keys[i] == maze[r][c]:
                            key = i
                            break
                    k |= 1 << key
                    visited[k][r][c] = True
                    queue.append([r, c, d + 1, k])

                elif maze[r][c] in locks:
                    lock = 0
                    for i in range(6):
                        if locks[i] == maze[r][c]:
                            lock = i
                            break
                    if k & 1 << lock:
                        visited[k][r][c] = True
                        queue.append([r, c, d + 1, k])

if success == False:
    print(-1)