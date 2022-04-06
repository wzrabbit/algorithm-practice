import sys
input = sys.stdin.readline

row, col = map(int, input().split())
canvas = []

for r in range(row):
    canvas.append(list(input().strip()))

for r in range(row):
    for c in range(col // 2):
        if canvas[r][c] != '.':
            canvas[r][col - c - 1] = canvas[r][c]
        elif canvas[r][col - c - 1] != '.':
            canvas[r][c] = canvas[r][col - c - 1]

for r in range(row):
    print(''.join(canvas[r]))
