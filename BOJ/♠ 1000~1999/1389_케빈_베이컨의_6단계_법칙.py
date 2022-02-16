import sys
input = sys.stdin.readline
user, rel = list(map(int, input().split(' ')))
inf = 10 ** 3
graph = [[inf for j in range(user)] for i in range(user)]

for i in range(rel):
    s, e = list(map(int, input().split(' ')))
    graph[s - 1][e - 1] = 1
    graph[e - 1][s - 1] = 1

for i in range(user):
    graph[i][i] = 0

for m in range(user):
    for s in range(user):
        for e in range(user):
            if s != e and graph[s][e] > graph[s][m] + graph[m][e]:
                graph[s][e] = graph[s][m] + graph[m][e]

min_ = 10 ** 5
person = 1
for i in range(user):
    current = 0
    for j in range(user):
        current += graph[i][j]
    if current < min_:
        min_ = current
        person = i + 1

print(person)