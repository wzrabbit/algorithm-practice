import sys
from collections import deque
input = sys.stdin.readline

vertex = int(input())
priority = [0]
time = [0]
maxTime = [0 for i in range(vertex + 1)]
graph = [[] for i in range(vertex + 1)]
queue = deque()

for v in range(1, vertex + 1):
    data = list(map(int, input().split()))
    time.append(data[0])
    priority.append(data[1])
    if data[1] == 0:
        queue.append(v)
        maxTime[v] = time[v]
    for i in range(2, len(data)):
        graph[data[i]].append(v)

while queue:
    v = queue.popleft()
    for i in graph[v]:
        priority[i] -= 1
        maxTime[i] = max(maxTime[v] + time[i], maxTime[i])
        if priority[i] == 0:
            queue.append(i)

print(max(maxTime))