n = int(input())
arr = list(map(int, input().split()))
query = []


def reverse(start, end):
    for i in range((end - start + 1) // 2):
        arr[start + i], arr[end - i] = arr[end - i], arr[start + i]


for i in range(len(arr)):
    if arr[i] != i + 1:
        query.append([i + 1, arr.index(i + 1) + 1])
        reverse(i, arr.index(i + 1))

print(len(query))
for i in range(len(query)):
    print(query[i][0], query[i][1])
