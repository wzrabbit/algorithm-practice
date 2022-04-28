import sys
input = sys.stdin.readline
print = sys.stdout.write

t = int(input())
for _ in range(t):
    arr = list(map(int, input().split()))
    arr.sort()
    res = (arr[0] + arr[1]) ** 2 + arr[2] ** 2
    print(str(res) + '\n')
