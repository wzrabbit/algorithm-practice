import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write
vertex, edge = list(map(int, input().split()))
graph = [[0 for j in range(vertex + 1)] for i in range(vertex + 1)]

for i in range(edge):
    f, s = list(map(int, input().split()))
    graph[f][s] = -1
    graph[s][f] = 1

for m in range(1, vertex + 1):
    for s in range(1, vertex + 1):
        for e in range(1, vertex + 1):
            if s != e and graph[s][e] == 0 and (graph[s][m] + graph[m][e]) in [2, -2]:
                if graph[s][m] + graph[m][e] == 2:
                    graph[s][e] = 1
                else:
                    graph[s][e] = -1

query = int(input())
for i in range(query):
    a, b = list(map(int, input().split()))
    print(str(graph[a][b]) + '\n')
