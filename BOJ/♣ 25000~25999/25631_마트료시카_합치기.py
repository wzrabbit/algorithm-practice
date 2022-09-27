N = int(input())
arr = list(map(int, input().split()))
arr.sort()
combo = 1
max_combo = 1

for i in range(1, N):
    if arr[i] == arr[i - 1]:
        combo += 1
        max_combo = max(max_combo, combo)
    else:
        combo = 1

print(max_combo)
