import sys
input = sys.stdin.readline

t = int(input())
for i in range(1, t + 1):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    total = 0

    a.sort()
    b.sort(key=lambda x: -x)

    for j in range(n):
        total += a[j] * b[j]

    print('Case #{}: {}'.format(i, total))
