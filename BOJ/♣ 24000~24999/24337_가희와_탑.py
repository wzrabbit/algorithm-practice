import sys
print = sys.stdout.write
n, a, b = list(map(int, input().split()))
res = [1 for i in range(n)]

if a + b > n + 1:
    print('-1')
else:
    u = n - a - b + 1
    if a == 1:
        res[0] = b
    else:
        for i in range(a - 1):
            res[i + u] = i + 1
    z = b
    if a == 1:
        z = b - 1
    for i in range(z):
        if i == z - 1:
            res[n - 1 - i] = max(a, z)
        else:
            res[n - 1 - i] = i + 1

    for i in range(len(res)):
        print(str(res[i]) + ' ')
