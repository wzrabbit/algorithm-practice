import sys
input = sys.stdin.readline
vertex, range_, edge = list(map(int, input().split(' ')))
item = list(map(int, input().split(' ')))
inf = 9999
graph = [[inf for j in range(vertex)] for i in range(vertex)]
max_ = 0

for i in range(edge):
    s, e, d = list(map(int, input().split(' ')))
    if graph[s - 1][e - 1] > d:
        graph[s - 1][e - 1] = d
        graph[e - 1][s - 1] = d

for i in range(vertex):
    graph[i][i] = 0

for m in range(vertex):
    for s in range(vertex):
        for e in range(vertex):
            if s != e and graph[s][m] + graph[m][e] < graph[s][e]:
                graph[s][e] = graph[s][m] + graph[m][e]

for i in range(vertex):
    current = 0
    for j in range(vertex):
        if graph[i][j] <= range_:
            current += item[j]
    if max_ < current:
        max_ = current

print(max_)
