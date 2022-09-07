grid = []
for _ in range(9):
    grid.append(list(map(int, input().split())))

max_value = -1
max_row = ''
max_col = ''

for r in range(9):
    for c in range(9):
        if grid[r][c] > max_value:
            max_row = r
            max_col = c
            max_value = grid[r][c]

print(max_value)
print(max_row + 1, max_col + 1)
