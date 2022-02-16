import sys
from collections import deque
input = sys.stdin.readline
graph = [[0 for j in range(501)] for i in range(501)]
visited = [[False for j in range(501)] for i in range(501)]

def writeArea(data, no):
    c1, r1, c2, r2 = list(map(int, data.split(' ')))
    if r1 > r2:
        temp = r1
        r1 = r2
        r2 = temp
    if c1 > c2:
        temp = c1
        c1 = c2
        c2 = temp

    for r in range(r1, r2 + 1):
        for c in range(c1, c2 + 1):
            if graph[r][c] < no:
                graph[r][c] = no

def bfs():
    queue = deque([[0, 0, 0]])
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]
    visited[0][0] = True

    while len(queue) > 0:
        r_, c_, h = queue.popleft()
        if r_ == 500 and c_ == 500:
            print(h)
            return
        for i in range(4):
            r = r_ + dr[i]
            c = c_ + dc[i]
            if r >= 0 and r <= 500 and c >= 0 and c <= 500 and visited[r][c] == False and graph[r][c] != 2:
                visited[r][c] = True
                if graph[r][c] == 0:
                    queue.appendleft([r, c, h])
                if graph[r][c] == 1:
                    queue.append([r, c, h + 1])
    print(-1)

danger = int(input())
for _ in range(danger):
    writeArea(input(), 1)
death = int(input())
for _ in range(death):
    writeArea(input(), 2)
bfs()