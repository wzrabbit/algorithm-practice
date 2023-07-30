import sys

input = sys.stdin.readline

N = int(input())
arr = list(map(int, input().split()))
arr *= 2

start = arr.index(min(arr))
success = True

for i in range(start, start + N - 1):
    if arr[i] > arr[i + 1]:
        success = False
        break

if success:
    if start == 0:
        print("1")
    else:
        print("2")
else:
    print("3")
