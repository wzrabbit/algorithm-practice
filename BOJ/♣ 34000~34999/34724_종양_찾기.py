import sys
input = sys.stdin.readline

R, C = map(int, input().split())
grid = [input().rstrip() for _ in range(R)]

for r in range(R - 1):
    for c in range(C - 1):
        if grid[r][c] == grid[r + 1][c] == grid[r][c + 1] == grid[r + 1][c + 1] == '1':
            print(1)
            exit()

print(0)
