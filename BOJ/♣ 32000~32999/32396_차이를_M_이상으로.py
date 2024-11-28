N, M = map(int, input().split())
arr = list(map(int, input().split()))
arr.append(-10 ** 12)

combo = 1
answer = 0

for i in range(1, N + 1):
    if abs(arr[i] - arr[i - 1]) < M:
        combo += 1
        continue

    answer += combo // 2
    combo = 1

print(answer)
