import sys
from collections import deque
input = sys.stdin.readline
station, line = list(map(int, input().split(' ')))
graph = [[] for i in range(station + line + 1)]
visited = [False] * (station + line + 1)

for i in range(station + 1, station + line + 1):
    data = list(map(int, input().split(' ')))
    data.pop()
    for j in range(len(data)):
        graph[i].append(data[j])
        graph[data[j]].append(i)

start, end = list(map(int, input().split(' ')))

queue = deque([[start, 0]])
visited[start] = True
found = False
while len(queue) > 0:
    c, d = queue.popleft()
    if c == end:
        found = True
        if start == end:
            print(0)
        else:
            print(d // 2 - 1)
        break
    for i in graph[c]:
        if visited[i] == False:
            visited[i] = True
            queue.append([i, d + 1])

if found == False:
    print(-1)
