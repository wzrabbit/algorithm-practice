N = int(input())
arr = list(map(int, input().split()))
combo = 1
answer = 1

for i in range(1, N):
    if arr[i] > arr[i - 1]:
        combo += 1
    else:
        combo = 1

    answer += combo

print(answer)
