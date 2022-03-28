import sys
input = sys.stdin.readline
place, road = list(map(int, input().split(' ')))
inf = 10 ** 9
graph = [[inf for j in range(place)] for i in range(place)]

for i in range(road):
    s, e, d = list(map(int, input().strip().split(' ')))
    if graph[s - 1][e - 1] > d:
        graph[s - 1][e - 1] = d
        graph[e - 1][s - 1] = d

for i in range(place):
    graph[i][i] = 0

for m in range(place):
    for s in range(place):
        for e in range(place):
            if s != e and graph[s][m] + graph[m][e] < graph[s][e]:
                graph[s][e] = graph[s][m] + graph[m][e]

answer, jhDist = -1, inf
jh, sh = list(map(int, input().split(' ')))
jh -= 1
sh -= 1

shortest = inf
for i in range(place):  # 2번 조건을 위한 최단거리 구하기
    for j in range(place):
        if i != jh and i != sh and graph[jh][i] + graph[sh][i] < shortest:
            shortest = graph[jh][i] + graph[sh][i]

for i in range(place):
    if i != jh and i != sh:  # 1번 조건
        if graph[jh][i] + graph[sh][i] == shortest:  # 2번 조건
            if graph[jh][i] <= graph[sh][i]:  # 3번 조건
                if graph[jh][i] < jhDist:  # 4번 조건
                    answer = i + 1
                    jhDist = graph[jh][i]

print(answer)
