import sys
from collections import deque
input = sys.stdin.readline

n, start, end = map(int, input().split())
graph = [[] for i in range(n + 1)]

for i in range(n - 1):
    s, e, d = map(int, input().split())
    graph[s].append((e, d))
    graph[e].append((s, d))

que = deque()
visited = [False] * (n + 1)
visited[start] = True
que.append((start, 0, 0))

while que:
    node, dist, max_ = que.popleft()

    if node == end:
        print(dist - max_)
        break

    for n_node, n_dist in graph[node]:
        if visited[n_node] == False:
            visited[n_node] = True
            que.append((n_node, dist + n_dist, max(max_, n_dist)))
