import sys
input = sys.stdin.readline

c = int(input())
m = 30
s = 0

for i in range(c):
    p = int(input())
    if m - p >= 0:
        m -= p
        s += 1
        if m == 0:
            m = 30
    elif m * 2 >= p:
        m = 30
        s += 1
    else:
        m = 30

print(s)
