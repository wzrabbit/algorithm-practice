N = int(input())
arr = list(map(int, input().split()))
combo = 0
score = 0

for i in range(N):
    if arr[i] == 1:
        combo += 1
    else:
        combo = 0

    score += combo

print(score)
