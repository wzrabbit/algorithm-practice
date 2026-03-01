import sys
input = sys.stdin.readline

arr = []

while True:
    cur = int(input())

    if cur == 0:
        break

    arr.append(cur)

arr.sort()

for i in range(len(arr) - 2):
    if arr[i] + arr[i + 1] > arr[i + 2]:
        print(arr[i], arr[i + 1], arr[i + 2])
        exit()

print('NIE')
