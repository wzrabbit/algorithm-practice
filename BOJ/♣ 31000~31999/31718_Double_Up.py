import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))

for i in range(N):
    while arr[i] % 2 == 0:
        arr[i] //= 2

db = dict()

for i in range(N):
    if arr[i] in db:
        db[arr[i]] += 1
    else:
        db[arr[i]] = 1

db = list(db.items())
db.sort(key=lambda x: -x[1])

print(db[0][1])
