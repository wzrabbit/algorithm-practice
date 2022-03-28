import sys
from collections import deque

nodes = int(sys.stdin.readline())
graph = [[] for i in range(nodes + 1)]
visited = [False] * (nodes + 1)
index = 1

for _ in range(nodes - 1):
    a, b = list(map(int, sys.stdin.readline().split(' ')))
    graph[a].append(b)
    graph[b].append(a)

order = list(map(int, sys.stdin.readline().split(' ')))
priority = [0] * (nodes + 1)
result = []

for i in range(1, nodes + 1):
    priority[order[i - 1]] = i

for i in range(nodes + 1):
    graph[i].sort(key=lambda x: priority[x])


def bfs():
    global index
    queue = deque([1])

    while index < nodes + 1 and len(queue) != 0:
        current = queue.popleft()
        result.append(current)
        for i in graph[current]:
            if visited[i] == False:
                visited[i] = True
                index += 1
                queue.append(i)


if order[0] == 1:
    visited[1] = True
    bfs()
    if order == result:
        print(1)
    else:
        print(0)
else:
    print(0)
