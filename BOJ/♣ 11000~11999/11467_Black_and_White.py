black, white = map(int, input().split())
need_merge_count = [1000 - black, 1000 - white]
symbol = ('@', '.')
grid = [['@', '.'] * 1000 for _ in range(2)]

for i in range(2):
    for j in range(i, 2000, 2):
        if need_merge_count[i] > 0:
            need_merge_count[i] -= 1
            grid[i][j + 1] = symbol[i]

print('2 2000')
print(''.join(grid[0]) + '\n' + ''.join(grid[1]))
