import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
arr = list(map(int, input().split()))
minus = 0
plus = 0

for i in range(len(arr)):
    if arr[i] > 0:
        arr[i] = 1
    else:
        arr[i] = -1

idx_plus = n
idx_minus = 1

if arr[-1] == -1:
    print('-1')
else:
    for i in range(n):
        if arr[i] == 1:
            print(str(idx_plus) + ' ')
            idx_plus -= 1
        else:
            print(str(idx_minus) + ' ')
            idx_minus += 1
