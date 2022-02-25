import sys
input = sys.stdin.readline
thing = int(input())
data = int(input())
graph = [[0 for j in range(thing)] for i in range(thing)]

for i in range(data):
    u, d = list(map(int, input().strip().split(' ')))
    graph[u - 1][d - 1] = 1
    graph[d - 1][u - 1] = -1

for m in range(thing):
    for s in range(thing):
        for e in range(thing):
            if s != e and graph[s][m] + graph[m][e] == 2:
                graph[s][e] = 1
            elif s != e and graph[s][m] + graph[m][e] == -2:
                graph[s][e] = -1

result = ''
for i in range(thing):
    count = 0
    for j in range(thing):
        if i != j and graph[i][j] == 0:
            count += 1
    result += str(count) + '\n'

print(result)
