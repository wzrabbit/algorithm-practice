import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write

vertex, edge, dist, start = map(int, input().split())
graph = [[] for _ in range(vertex + 1)]
visited = [-1] * (vertex + 1)

for _ in range(edge):
    s, e = map(int, input().split())
    graph[s].append(e)

q = deque([start])
visited[start] = 0

while len(q):
    cur = q.popleft()
    for next in graph[cur]:
        if visited[next] == -1:
            q.append(next)
            visited[next] = visited[cur] + 1

if dist not in visited:
    print('-1')
else:
    for i in range(vertex + 1):
        if visited[i] == dist:
            print(f'{i}\n')
