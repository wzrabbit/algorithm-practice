R, C = map(int, input().split())
grid = []

for _ in range(R):
    grid.append(list(input()))
    
zero_count = 0
one_count = 0

for r in range(R):
    for c in range(C):
        if grid[r][c] == '0':
            zero_count += 1
        else:
            one_count += 1
            
print(min(zero_count, one_count))
