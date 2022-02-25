import sys
import copy
from collections import deque
vertex, edge = map(int, sys.stdin.readline().split())
visited = [False for i in range(vertex + 1)]
count = 0
graph = {}

for i in range(1, vertex + 1):
    graph[i] = []
for i in range(edge):
    start, end = map(int, sys.stdin.readline().split())
    graph[start].append(end)
    graph[end].append(start)


def bfs(startVertex):
    q = deque([startVertex])

    while len(q):
        v = q.popleft()

        for n in graph[v]:
            if visited[n] == False:
                visited[n] = True
                q.append(n)


for i in range(1, vertex + 1):
    if visited[i] == False:
        count += 1
        bfs(i)

print(count)
