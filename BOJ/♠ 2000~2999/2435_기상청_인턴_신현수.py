N, K = map(int, input().split())
arr = list(map(int, input().split()))

best = -999999

for i in range(N - K + 1):
    best = max(best, sum(arr[i : i + K]))

print(best)
