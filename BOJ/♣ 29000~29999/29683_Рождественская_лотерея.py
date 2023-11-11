N, A = map(int, input().split())
arr = list(map(int, input().split()))
total = 0

for i in range(N):
    total += arr[i] // A

print(total)
