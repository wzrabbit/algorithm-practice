N = int(input())
arr = list(map(int, input().split()))

cut_count = 1
max_combo = 1
combo = 1

for i in range(1, N):
    if arr[i - 1] > arr[i]:
        cut_count += 1
        combo = 1
    else:
        combo += 1
    
    max_combo = max(max_combo, combo)

print(cut_count, max_combo)
