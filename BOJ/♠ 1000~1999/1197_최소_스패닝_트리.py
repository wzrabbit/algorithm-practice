import sys
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

v, e = list(map(int, input().split()))
line = []
union = [0 for i in range(v + 1)]
rank = [1 for i in range(v + 1)]

for i in range(e):
    line.append(list(map(int, input().split())))
line.sort(key = lambda x: x[2])

count = 0
weight = 0
for i in range(len(line)):
    a, b, w = line[i]
    if merge(a, b):
        weight += w
        count += 1
    if count == v - 1:
        break

print(weight)