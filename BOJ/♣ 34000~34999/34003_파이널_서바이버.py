import math

grid = []

for _ in range(8):
    grid.append(input())

left_count = 0

for r in range(8):
    for c in range(8):
        if grid[r][c] == 'O':
            left_count += 1

max_life = 0
answer_r = 1
answer_c = 1

for r in range(7):
    for c in range(7):
        cur_life = [grid[r][c], grid[r + 1][c], grid[r][c + 1], grid[r + 1][c + 1]].count('O')
        
        if cur_life > max_life:
            answer_r = r + 1
            answer_c = c + 1
            max_life = cur_life

print(answer_r, answer_c)
print(1 - math.comb(left_count - max_life, 4) / math.comb(left_count, 4))
