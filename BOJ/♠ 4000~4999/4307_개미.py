import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    land, num = map(int, input().split())
    max_ = []
    min_ = []

    for i in range(num):
        c = int(input())
        if c >= land - c:
            max_.append(c)
            min_.append(land - c)
        else:
            max_.append(land - c)
            min_.append(c)

    print(max(min_), max(max_))
