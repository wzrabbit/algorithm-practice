while True:
    N = int(input())
    if N == 0:
        break
    
    arr = sorted(list(map(int, input().split())))
    max_combo = 1
    current_combo = 1
    
    for i in range(1, N):
        if arr[i] == arr[i - 1] + 1:
            current_combo += 1
            max_combo = max(current_combo, max_combo)
        else:
            current_combo = 1
            
    print(max_combo)