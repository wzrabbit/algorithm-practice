# imos
S, E = map(int, input().split())
N = int(input())
query = []
lst = [S, E]
db = dict()

for _ in range(N):
    query.append(list(map(int, input().split())))
    lst.append(query[-1][0])
    lst.append(query[-1][0] + 0.1)
    lst.append(query[-1][1])
    lst.append(query[-1][1] + 0.1)

lst = list(set(lst))
lst.sort()

for i in range(len(lst)):
    db[lst[i]] = i

prefix = [0] * (len(lst) + 1)
for i in range(N):
    prefix[db[query[i][0]]] += 1
    prefix[db[query[i][1]] + 1] -= 1

max_ = 0
min_ = 1000000
cur = 0
for i in range(len(lst)):
    cur += prefix[i]

    if db[S] <= i <= db[E]:
        max_ = max(max_, cur)
        min_ = min(min_, cur)

print(min_, max_)
