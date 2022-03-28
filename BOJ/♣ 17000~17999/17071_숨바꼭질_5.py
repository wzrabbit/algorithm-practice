import sys
from collections import deque
visited = [[-1] * 500001, [-1] * 500001]
start, end = list(map(int, sys.stdin.readline().split()))

success = False
section = 0
speed = 1
queue = deque([[start, 0]])
visited[0][start] = 0
while len(queue):
    n, t = queue.popleft()
    v = 1
    if t % 2 == 0:
        v = 0

    if t != section:
        section += 1
        end += speed
        speed += 1
        if end > 500000:
            break
        if visited[v][end] != -1:
            print(t)
            success = True
            break
    if n == end:
        print(t)
        success = True
        break

    if v == 0:
        v = 1
    else:
        v = 0

    if n <= 250000 and visited[v][n * 2] == -1:
        visited[v][n * 2] = t + 1
        queue.append([n * 2, t + 1])
    if n < 500000 and visited[v][n + 1] == -1:
        visited[v][n + 1] = t + 1
        queue.append([n + 1, t + 1])
    if n > 0 and visited[v][n - 1] == -1:
        visited[v][n - 1] = t + 1
        queue.append([n - 1, t + 1])

if success == False:
    print(-1)
