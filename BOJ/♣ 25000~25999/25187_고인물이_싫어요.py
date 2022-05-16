import sys
input = sys.stdin.readline
print = sys.stdout.write

tank, pipe, query = map(int, input().split())
item = list(map(int, input().split()))
union = [-1 for i in range(tank)]
rank = [1 for i in range(tank)]
pollution = [0 for i in range(tank)]


def getParent(child):
    if union[child] == -1:
        return child
    union[child] = getParent(union[child])
    return union[child]


def merge(a, b):
    a = getParent(a)
    b = getParent(b)
    if a != b:
        if rank[a] > rank[b]:
            union[b] = a
            rank[a] += rank[b]
        else:
            union[a] = b
            rank[b] += rank[a]


for i in range(tank):
    if item[i] == 0:
        item[i] = -1

for i in range(pipe):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    merge(a, b)

    pollution[union[i]] += item[i]

for q in range(query):
    q = int(input()) - 1
    if pollution[getParent(q)] >= 1:
        print('1\n')
    else:
        print('0\n')
