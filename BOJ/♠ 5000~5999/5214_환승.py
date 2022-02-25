import sys
from collections import deque
input = sys.stdin.readline
station, connect, tube = list(map(int, input().split(' ')))
graph = [[] for i in range(station + tube + 1)]
visited = [False] * (station + tube + 1)
visited[1] = True

for i in range(station + 1, station + tube + 1):
    data = list(map(int, input().split(' ')))
    for j in range(connect):
        graph[i].append(data[j])
        graph[data[j]].append(i)

queue = deque([[1, 0]])
found = False
while len(queue) > 0:
    c, d = queue.popleft()
    if c == station:
        found = True
        print(d // 2 + 1)
        break
    for i in graph[c]:
        if visited[i] == False:
            visited[i] = True
            queue.append([i, d + 1])

if found == False:
    print(-1)
