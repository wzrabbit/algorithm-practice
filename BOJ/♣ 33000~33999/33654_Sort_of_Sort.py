# 일부러 틀리도록 설계한 코드

import sys
print = sys.stdout.write

N = int(input())
arr = list(map(int, input().split()))
prev = -199999

for i in range(N):
    if prev <= arr[i]:
        print(f'{arr[i]} ')
        prev = arr[i]
