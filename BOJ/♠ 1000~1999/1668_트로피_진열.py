N = int(input())
arr = []

for i in range(N):
    arr.append(int(input()))

left = 1
right = 1

cur = arr[0]

for i in range(1, N):
    if arr[i] > cur:
        left += 1
        cur = arr[i]

cur = arr[-1]

for i in range(N - 2, -1, -1):
    if arr[i] > cur:
        right += 1
        cur = arr[i]

print(left)
print(right)
