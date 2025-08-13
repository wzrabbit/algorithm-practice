N = int(input())
arr = []

for _ in range(N):
    arr.append(float(input()))

arr.sort()

print('{:.2f}'.format(arr[1]))
