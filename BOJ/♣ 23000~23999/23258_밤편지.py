import sys
import copy
input = sys.stdin.readline
print = sys.stdout.write
house, query = list(map(int, input().split(' ')))
inf = 10 ** 15
floyd = []
graph = []

for i in range(house):
    data = list(map(int, input().split(' ')))
    for j in range(house):
        if data[j] == 0:
            data[j] = inf
    floyd.append(data)

for i in range(house):
    floyd[i][i] = 0

graph.append(copy.deepcopy(floyd))
for m in range(house):
    for s in range(house):
        for e in range(house):
            if s != e and floyd[s][e] > floyd[s][m] + floyd[m][e]:
                floyd[s][e] = floyd[s][m] + floyd[m][e]
    graph.append(copy.deepcopy(floyd))

for i in range(query):
    limit, start, end = list(map(int, input().split(' ')))
    limit -= 1
    start -= 1
    end -= 1
    current = graph[limit][start][end]
    if current == inf:
        print('-1\n')
    else:
        print(str(current) + '\n')
