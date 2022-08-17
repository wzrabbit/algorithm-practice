import sys
input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
even = []
odd = []

for i in range(N):
    if i % 2 == 0:
        even.append(arr[i])
    else:
        odd.append(arr[i])

even.sort()
odd.sort()

final_arr = []
for i in range(N // 2):
    final_arr.append(even[i])
    final_arr.append(odd[i])

if N % 2 == 1:
    final_arr.append(even[-1])

if final_arr == sorted(final_arr):
    print('YES')
else:
    print('NO')
