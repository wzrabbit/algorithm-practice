import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write

vertex, edge, start = map(int, input().split())
graph = [[] for _ in range(vertex + 1)]
visited = [False] * (vertex + 1)
order = [0] * (vertex + 1)
no = 1

for i in range(edge):
    s, e = map(int, input().split())
    graph[s].append(e)
    graph[e].append(s)

for i in range(1, vertex + 1):
    graph[i].sort(key=lambda x: -x)

que = deque()
que.append(start)
visited[start] = True

while len(que):
    current = que.popleft()
    order[current] = str(no)
    no += 1

    for i in range(len(graph[current])):
        if visited[graph[current][i]] == False:
            visited[graph[current][i]] = True
            que.append(graph[current][i])

for i in range(1, vertex + 1):
    print(str(order[i]) + '\n')
