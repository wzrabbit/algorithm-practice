N = int(input())
arr = list(map(int, input().split()))

result = []

for i in range(N):
    result.insert(i - arr[i], i + 1)

print(*result)
