import sys
from collections import deque
input = sys.stdin.readline

vertex, edge = map(int, input().split())
graph = [[] for _ in range(vertex + 1)]


for _ in range(edge):
    s, e, l = map(int, input().split())
    graph[s].append([e, l])
    graph[e].append([s, l])

start, end = map(int, input().split())


def bfs(limit):
    global start
    global end
    que = deque()
    visited = [False] * (vertex + 1)
    visited[start] = True
    que.append(start)

    while que:
        current = que.popleft()
        if current == end:
            return True
        for n, l in graph[current]:
            if visited[n] == False and limit <= l:
                visited[n] = True
                que.append(n)

    return False


low = 1
high = 1000000000
mid = 0
while low <= high:
    mid = (low + high) // 2
    if bfs(mid):
        low = mid + 1
    else:
        high = mid - 1
print(high)
