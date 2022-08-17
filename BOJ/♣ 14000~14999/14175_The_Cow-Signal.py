R, C, Z = map(int, input().split())
grid = []
for _ in range(R):
    grid.append(list(input()))
canvas = [[''] * (C * Z) for _ in range(R * Z)]


def paint(r, c, pen):
    r *= Z
    c *= Z
    for i in range(r, r + Z):
        for j in range(c, c + Z):
            canvas[i][j] = pen


for i in range(R):
    for j in range(C):
        paint(i, j, grid[i][j])

for i in range(R * Z):
    print(''.join(canvas[i]))
