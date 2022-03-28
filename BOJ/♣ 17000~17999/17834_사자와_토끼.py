import sys
from collections import deque

bush, road = list(map(int, sys.stdin.readline().split()))
graph = [[] for i in range(bush + 1)]
visited = [0] * (bush + 1)

for i in range(road):
    a, b = list(map(int, sys.stdin.readline().split()))
    graph[a].append(b)
    graph[b].append(a)


def bfs():
    queue = deque([[1, 1]])
    visited[1] = 1
    a = 1
    b = 0

    while len(queue):
        l, f = queue.popleft()
        for i in graph[l]:
            if visited[i] == 0:
                if f == 1:
                    visited[i] = 2
                    queue.append([i, 2])
                    b += 1
                else:
                    visited[i] = 1
                    queue.append([i, 1])
                    a += 1
            elif visited[i] == f:
                return 0
    return a * b * 2


result = bfs()
print(result)
