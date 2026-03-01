R, C = map(int, input().split())
grid = [input() for _ in range(R)]
plank_count = 0

for r in range(R):
    for c in range(C):
        if grid[r][c] == '|' and (r == 0 or grid[r][c] != grid[r - 1][c]):
            plank_count += 1
        
        if grid[r][c] == '-' and (c == 0 or grid[r][c] != grid[r][c - 1]):
            plank_count += 1

print(plank_count)
