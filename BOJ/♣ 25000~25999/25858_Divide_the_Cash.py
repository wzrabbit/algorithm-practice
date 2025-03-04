N, D = map(int, input().split())
arr = []

for _ in range(N):
    arr.append(int(input()))

for i in range(N):
    print(D * arr[i] // sum(arr))
