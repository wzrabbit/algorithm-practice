import sys
input = sys.stdin.readline

t = int(input())
for _ in range(t):
    treasure = []
    n = int(input())
    for __ in range(n):
        treasure.append(list(map(int, input().split())))

    treasure.sort(key=lambda x: (x[0] + x[1]) * -1)
    result = 0

    for i in range(0, n, 2):
        result += treasure[i][0]
    for i in range(1, n, 2):
        result -= treasure[i][1]

    print(result)
