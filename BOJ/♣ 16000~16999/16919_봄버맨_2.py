R, C, N = map(int, input().split())
grid = [list(input()) for _ in range(R)]
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)

if N % 2 == 0:
    for _ in range(R):
        print('O' * C)
    exit()

if N == 1:
    for r in range(R):
        print(''.join(grid[r]))
    exit()

for r in range(R):
    for c in range(C):
        if grid[r][c] == '.':
            grid[r][c] = 'X'

for r in range(R):
    for c in range(C):
        if grid[r][c] == 'O':
            grid[r][c] = '.'

            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]

                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] != 'O':
                    grid[nr][nc] = '.'

if N % 4 == 3:
    for r in range(R):
        print(''.join(grid[r]).replace('X', 'O'))
    exit()

for r in range(R):
    for c in range(C):
        if grid[r][c] == '.':
            grid[r][c] = 'O'

for r in range(R):
    for c in range(C):
        if grid[r][c] == 'X':
            grid[r][c] = '.'

            for i in range(4):
                nr = r + dr[i]
                nc = c + dc[i]

                if 0 <= nr < R and 0 <= nc < C and grid[nr][nc] != 'X':
                    grid[nr][nc] = '.'

for r in range(R):
    print(''.join(grid[r]).replace('X', 'O'))
