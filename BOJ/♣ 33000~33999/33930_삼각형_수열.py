N = int(input())

if N == 1:
    print(1)
    exit()

if N <= 3:
    print(-1)
    exit()

grid = [
    [4],
    [1, 3],
    [3, 4, 2],
    [4, 2, 3, 4],
]

for i in range(5, N + 1):
    grid.append([i] * i)

    for j in range(1, i - 1, 2):
        grid[-1][j], grid[-3][j - 1] = grid[-3][j - 1], grid[-1][j]
    
    if i % 2 == 0:
        grid[-1][-1], grid[0][0] = grid[0][0], grid[-1][-1]

for i in range(N):
    print(*grid[i])
