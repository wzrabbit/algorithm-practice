import sys
input = sys.stdin.readline
vertex = int(input())
edge = int(input())
inf = 99999999
graph = [[inf for j in range(vertex)] for i in range(vertex)]

for i in range(edge):
    s, e, d = list(map(int, input().split(' ')))
    if graph[s - 1][e - 1] > d:
        graph[s - 1][e - 1] = d

for i in range(vertex):
    graph[i][i] = 0

#m : 중간점, s : 시작점, e : 도착점
# 시작 -> 도착 보다 시작 -> 중간 -> 도착 이 더 가까울 경우 값을 갱신
for m in range(vertex):
    for s in range(vertex):
        for e in range(vertex):
            if s != e and graph[s][m] + graph[m][e] < graph[s][e]:
                graph[s][e] = graph[s][m] + graph[m][e]

for i in range(vertex):
    for j in range(vertex):
        if graph[i][j] == inf:
            graph[i][j] = 0
        print(graph[i][j], end = ' ')
    print()