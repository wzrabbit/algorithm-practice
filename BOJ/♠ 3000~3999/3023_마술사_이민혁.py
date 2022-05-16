import sys
input = sys.stdin.readline
print = sys.stdout.write

row, col = map(int, input().split())
card = [['' for c in range(col * 2)] for r in range(row * 2)]
original = []


for _ in range(row):
    original.append(list(input().strip()))

for r in range(row):
    for c in range(col):
        card[r][c] = original[r][c]

for r in range(row):
    for c in range(col, col * 2):
        card[r][c] = original[r][col * 2 - c - 1]

for r in range(row, row * 2):
    for c in range(col):
        card[r][c] = original[row * 2 - r - 1][c]

for r in range(row, row * 2):
    for c in range(col, col * 2):
        card[r][c] = original[row * 2 - r - 1][col * 2 - c - 1]

err_r, err_c = map(int, input().split())
if card[err_r - 1][err_c - 1] == '.':
    card[err_r - 1][err_c - 1] = '#'
else:
    card[err_r - 1][err_c - 1] = '.'

for i in range(row * 2):
    print(''.join(card[i]) + '\n')
