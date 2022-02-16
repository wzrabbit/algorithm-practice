import sys
import copy
input = sys.stdin.readline
print = sys.stdout.write
city, road, query = list(map(int, input().split(' ')))
dog = list(map(int, input().strip().split(' ')))
index = ['' for i in range(city)]
inf = 10 ** 10
floyd = [[inf for j in range(city)] for i in range(city)]
dogFloyd = [[inf for j in range(city)] for i in range(city)]

for i in range(len(dog)):
    dog[i] = [i, dog[i]]
dog.sort(key = lambda x: x[1])
for i in range(len(dog)):
    index[dog[i][0]] = i

for i in range(city):
    for j in range(city):
        dogFloyd[i][j] = max(dog[index[i]][1], dog[index[j]][1])

for i in range(road):
    s, e, d = list(map(int, input().split(' ')))
    s -= 1
    e -= 1
    if floyd[s][e] > d:
        floyd[s][e] = d
        floyd[e][s] = d

for i in range(city):
    for j in range(city):
        if i == j:
            floyd[i][i] = 0

for t in range(city):
    m = dog[t][0]
    c = dog[t][1]
    for s in range(city):
        for e in range(city):
            if floyd[s][m] + floyd[m][e] + max(dogFloyd[s][e], c) < floyd[s][e] + dogFloyd[s][e]:
                floyd[s][e] = floyd[s][m] + floyd[m][e]
                dogFloyd[s][e] = max(dogFloyd[s][e], c)

for i in range(query):
    start, end = list(map(int, input().split(' ')))
    start -= 1
    end -= 1
    fastest = floyd[start][end] + dogFloyd[start][end]
    if fastest >= inf:
        print('-1\n')
    else:
        print(str(fastest) + '\n')