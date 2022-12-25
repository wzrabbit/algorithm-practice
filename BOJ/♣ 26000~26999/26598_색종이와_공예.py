import sys
input = sys.stdin.readline


def is_square(start_r, start_c):
    if checked[start_r][start_c]:
        return True

    alphabet = grid[start_r][start_c]
    width = 1
    height = 1

    for c in range(start_c + 1, C + 1):
        if grid[start_r][c] != alphabet:
            break
        checked[start_r][c] = True
        width += 1

    for r in range(start_r + 1, R + 2):
        all_diff = True
        all_same = True
        for c in range(start_c, start_c + width):
            if grid[r][c] == alphabet:
                all_diff = False
                checked[r][c] = True
            else:
                all_same = False

        if not all_diff and not all_same:
            return False

        if all_diff:
            break

        height += 1

    for r in range(start_r, start_r + height):
        if grid[r][start_c - 1] == alphabet:
            return False
        if grid[r][start_c + width] == alphabet:
            return False

    for c in range(start_c, start_c + width):
        if grid[start_r - 1][c] == alphabet:
            return False
        if grid[start_r + height][c] == alphabet:
            return False

    return True


R, C = map(int, input().split())
grid = []
checked = [[False] * (C + 2) for _ in range(R + 2)]
success = True

grid.append(['.'] * (C + 2))
for _ in range(R):
    grid.append(['.'] + list(input().strip()) + ['.'])
grid.append(['.'] * (C + 2))

for r in range(1, R + 1):
    for c in range(1, C + 1):
        success &= is_square(r, c)

if success:
    print('dd')
else:
    print('BaboBabo')
