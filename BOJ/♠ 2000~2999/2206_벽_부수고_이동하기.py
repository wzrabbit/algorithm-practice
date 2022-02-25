import sys
from collections import deque
row, col = list(map(int, sys.stdin.readline().split(' ')))
visited = [[[False] * col for i in range(row)] for j in range(2)]

maze = []
for _ in range(row):
    maze.append(list(map(int, sys.stdin.readline().strip())))

queue = deque([[0, 0, 1, 0]])
visited[0][0][0] = True
success = False

while len(queue):
    r, c, d, b = queue.popleft()

    if r == row - 1 and c == col - 1:
        print(d)
        success = True
        break

    if r > 0:
        if visited[b][r - 1][c] == False:
            if maze[r - 1][c] == 0:
                visited[b][r - 1][c] = True
                queue.append([r - 1, c, d + 1, b])
            elif b == 0:
                visited[1][r - 1][c] = True
                queue.append([r - 1, c, d + 1, 1])

    if r < row - 1:
        if visited[b][r + 1][c] == False:
            if maze[r + 1][c] == 0:
                visited[b][r + 1][c] = True
                queue.append([r + 1, c, d + 1, b])
            elif b == 0:
                visited[1][r + 1][c] = True
                queue.append([r + 1, c, d + 1, 1])

    if c > 0:
        if visited[b][r][c - 1] == False:
            if maze[r][c - 1] == 0:
                visited[b][r][c - 1] = True
                queue.append([r, c - 1, d + 1, b])
            elif b == 0:
                visited[1][r][c - 1] = True
                queue.append([r, c - 1, d + 1, 1])

    if c < col - 1:
        if visited[b][r][c + 1] == False:
            if maze[r][c + 1] == 0:
                visited[b][r][c + 1] = True
                queue.append([r, c + 1, d + 1, b])
            elif b == 0:
                visited[1][r][c + 1] = True
                queue.append([r, c + 1, d + 1, 1])

if success == False:
    print(-1)
