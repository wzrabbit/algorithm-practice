import sys
input = sys.stdin.readline
print = sys.stdout.write

dr = (-1, 0, -1, 0, 1, 0, 1, 0)
dc = (0, -1, 0, 1, 0, -1, 0, 1)
no = 1

while True:
    N = int(input())
    if N == 0:
        break

    grid = []
    R = N * 4 - 1
    C = N * 4 + 3
    ice = [[' '] * C for _ in range(R)]
    for _ in range(N):
        grid.append(list(map(int, input().split())))

    for r in range(R):
        ice[r][0] = '*'
        ice[r][C - 1] = '*'

    for c in range(C):
        ice[0][c] = '*'
        ice[R - 1][c] = '*'

    for r in range(N):
        for c in range(N):
            if grid[r][c] == 1:
                ice[r * 4 + 1][c * 4 + 1: c * 4 + 6] = 'H-O-H'
            elif grid[r][c] == -1:
                ice[r * 4 - 1][c * 4 + 3] = 'H'
                ice[r * 4 + 0][c * 4 + 3] = '|'
                ice[r * 4 + 1][c * 4 + 3] = 'O'
                ice[r * 4 + 2][c * 4 + 3] = '|'
                ice[r * 4 + 3][c * 4 + 3] = 'H'
            else:
                ice[r * 4 + 1][c * 4 + 3] = 'O'

    for r in range(N):
        for c in range(N):
            if grid[r][c] == 0:
                for i in range(0, 8, 2):
                    r1 = r * 4 + 1 + dr[i] * 2
                    c1 = c * 4 + 3 + dc[i] * 2
                    r2 = r * 4 + 1 + dr[i + 1] * 2
                    c2 = c * 4 + 3 + dc[i + 1] * 2

                    if 0 < r1 < R - 1 and 0 < c1 < C - 1 and 0 < r2 < R - 1 and 0 < c2 < C - 1 and ice[r1][c1] == ' ' and ice[r2][c2] == ' ':
                        ice[r1][c1] = 'H'
                        ice[r1 - dr[i]][c1 - dc[i]] = '|'
                        ice[r2][c2] = 'H'
                        ice[r2 - dr[i + 1]][c2 - dc[i + 1]] = '-'
                        break

    if no != 1:
        print('\n')
    print(f'Case {no}:\n\n')

    for r in range(R):
        for c in range(C):
            print(ice[r][c])
        print('\n')

    no += 1
