N, Z = map(int, input().split())
grid = []
for _ in range(N):
    grid.append(input().split())
canvas = [[''] * (N * Z) for _ in range(N * Z)]


def paint(r, c, pen):
    r *= Z
    c *= Z
    for i in range(r, r + Z):
        for j in range(c, c + Z):
            canvas[i][j] = pen


for i in range(N):
    for j in range(N):
        paint(i, j, grid[i][j])

for i in range(N * Z):
    print(' '.join(canvas[i]))
