N = int(input())
arr = list(map(int, input().split()))
counts = [0] * 1001

for i in range(N):
    counts[arr[i]] += 1

answer = N

for i in range(1, 1001):
    answer -= max(0, counts[i] - 2)

print(answer)
