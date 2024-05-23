N = int(input())
arr = list(map(int, input().split()))

combo = 1
max_combo = 1

for i in range(1, N):
    if arr[i] >= arr[i - 1]:
        combo += 1
    else:
        combo = 1
    
    max_combo = max(max_combo, combo)
    
combo = 1

for i in range(1, N):
    if arr[i] <= arr[i - 1]:
        combo += 1
    else:
        combo = 1
    
    max_combo = max(max_combo, combo)
    
print(max_combo)
