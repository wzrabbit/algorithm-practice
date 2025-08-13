N, K = map(int, input().split())
arr = list(map(int, input().split()))

arr.sort()

if arr[-1] > K:
    print(0)
    exit()

if arr[0] <= 0:
    print(-1)
    exit()

answer = 0

for i in range(1, N):
    matched = (K - arr[i]) // arr[0]
    answer += matched

print(answer + 1)
