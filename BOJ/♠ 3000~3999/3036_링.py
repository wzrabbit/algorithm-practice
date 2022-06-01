import sys


def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)


print = sys.stdout.write
n = int(input())
arr = list(map(int, input().split()))
a = arr[0]

for i in range(1, n):
    b = arr[i]
    g = gcd(a, arr[i])
    print(f'{a // g}/{b // g}\n')
