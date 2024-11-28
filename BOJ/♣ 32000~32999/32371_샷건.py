keyboards = []
dr = (0, -1, 1, 0, 0, -1, -1, 1, 1)
dc = (0, 0, 0, -1, 1, 1, -1, 1, -1)

for _ in range(4):
    keyboards.append(input())

broken = list(input())
broken.sort()

for r in range(1, 3):
    for c in range(1, 9):
        adjacent = []

        for i in range(9):
            adj_r = r + dr[i]
            adj_c = c + dc[i]
            adjacent.append(keyboards[adj_r][adj_c])

        adjacent.sort()

        if adjacent == broken:
            print(keyboards[r][c])
            exit(0)
