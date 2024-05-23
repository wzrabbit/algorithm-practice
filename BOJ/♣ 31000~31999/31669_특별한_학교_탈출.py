R, C = map(int, input().split())
grid = []

for _ in range(R):
    grid.append(list(input()))

for c in range(C):
    success = True

    for r in range(R):
        if grid[r][c] == "O":
            success = False
            break

    if success:
        print(c + 1)
        exit()

print("ESCAPE FAILED")
