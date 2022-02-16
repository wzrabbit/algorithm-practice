import sys
import math
input = sys.stdin.readline

def find(a):
    if union[a] == 0:
        return a
    union[a] = find(union[a])
    return union[a]

def merge(a, b):
    a = find(a)
    b = find(b)
    if a == b:
        return False
    if rank[a] > rank[b]:
        union[b] = a
        rank[a] += rank[b]
    else:
        union[a] = b
        rank[b] += rank[a]
    return True

def getDistance(x1, y1, x2, y2):
    return math.sqrt((x2 - x1) ** 2 + (y2 - y1) ** 2)

v, e = list(map(int, input().split()))
god = [[]]
line = []
union = [0 for i in range(v + 1)]
rank = [1 for i in range(v + 1)]

for i in range(v):
    god.append(list(map(int, input().split())))

for i in range(e):
    a, b = list(map(int, input().split()))
    merge(a, b)

for i in range(1, v + 1):
    for j in range(i + 1, v + 1):
        d = getDistance(god[i][0], god[i][1], god[j][0], god[j][1])
        line.append([i, j, d])
line.sort(key = lambda x: x[2])

count = v
weight = 0
for i in range(1, len(union)):
    if union[v] == 0:
        v -= 1

for i in range(len(line)):
    if count == v - 1:
        break
    a, b, d = line[i]
    if merge(a, b):
        count += 1
        weight += d

print(format(weight, '.2f'))