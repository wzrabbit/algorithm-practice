N = int(input())
arr = list(map(int, input().split()))
max_index = arr.index(max(arr))

for i in reversed(range(max_index)):
    if arr[i] >= arr[i + 1]:
        print('NO')
        exit()

for i in range(max_index, N - 1):
    if arr[i] <= arr[i + 1]:
        print('NO')
        exit()

print('YES')
