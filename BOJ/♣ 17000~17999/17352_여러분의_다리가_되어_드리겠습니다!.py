import sys
from collections import deque
input = sys.stdin.readline
vertex = int(input())
graph = [[] for i in range(vertex + 1)]
visited = [False for i in range(vertex + 1)]
for i in range(vertex - 2):
    a, b = list(map(int, input().split()))
    graph[a].append(b)
    graph[b].append(a)

queue = deque([1])
while len(queue):
    c = queue.popleft()
    for i in graph[c]:
        if visited[i] == False:
            visited[i] = True
            queue.append(i)

for i in range(2, vertex + 1):
    if visited[i] == False:
        print(f'1 {i}')
        break
