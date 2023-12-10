N = int(input())
grid = [["."] * 20 for _ in range(10)]

for i in range(N):
    pos = input()
    row = pos[0]
    col = int(pos[1:])

    grid[ord(row) - ord("A")][int(col) - 1] = "o"

for i in range(10):
    print(f"{''.join(grid[i])}")
