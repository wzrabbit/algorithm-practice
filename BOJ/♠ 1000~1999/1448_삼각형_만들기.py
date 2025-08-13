import sys
input = sys.stdin.readline

N = int(input())
arr = []

for _ in range(N):
    arr.append(int(input()))

arr.sort()
answer = -1

for i in reversed(range(N - 2)):
    if arr[i] + arr[i + 1] > arr[i + 2]:
        answer = arr[i] + arr[i + 1] + arr[i + 2]
        break

print(answer)
