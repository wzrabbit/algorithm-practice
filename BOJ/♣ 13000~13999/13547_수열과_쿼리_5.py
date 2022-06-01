import sys
import functools
import math
input = sys.stdin.readline
print = sys.stdout.write


def mos_compare(a, b):
    if a[1] // s > b[1] // s:
        return 1
    elif a[1] // s < b[1] // s:
        return -1
    else:
        if a[2] > b[2]:
            return 1
        else:
            return -1


def add(x):
    global kind
    num[x] += 1
    if num[x] == 1:
        kind += 1


def delete(x):
    global kind
    num[x] -= 1
    if num[x] == 0:
        kind -= 1


n = int(input())
arr = tuple(map(int, input().split()))
s = int(math.sqrt(n))

q = int(input())
query = []
result = [''] * q
num = [0] * 1000001
for i in range(q):
    a, b = map(int, input().split())
    query.append((i, a - 1, b - 1))

query.sort(key=functools.cmp_to_key(mos_compare))

kind = 0
l = query[0][1]
r = query[0][2]

for i in range(l, r + 1):
    add(arr[i])

for i in range(q):
    idx, a, b = query[i]

    while l < a:
        delete(arr[l])
        l += 1

    while l > a:
        l -= 1
        add(arr[l])

    while r < b:
        r += 1
        add(arr[r])

    while r > b:
        delete(arr[r])
        r -= 1

    result[idx] = str(kind)

for i in range(q):
    print(result[i] + '\n')
