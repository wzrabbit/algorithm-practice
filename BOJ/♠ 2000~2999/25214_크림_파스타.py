import sys
input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
arr = list(map(int, input().split()))
gap = 0
min_ = 10 ** 10
max_ = 0

for i in range(N):
    min_ = min(arr[i], min_)
    if arr[i] - min_ > gap:
        gap = arr[i] - min_
    print(f'{gap} ')
