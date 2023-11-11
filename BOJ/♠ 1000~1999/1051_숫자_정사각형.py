R, C = map(int, input().split())
grid = []


def is_answer(start_r, start_c, size):
    return (
        grid[start_r][start_c]
        == grid[start_r][start_c + size - 1]
        == grid[start_r + size - 1][start_c]
        == grid[start_r + size - 1][start_c + size - 1]
    )


for _ in range(R):
    grid.append(list(map(int, list(input()))))

for i in reversed(range(1, min(R, C) + 1)):
    for r in range(R - i + 1):
        for c in range(C - i + 1):
            if is_answer(r, c, i):
                print(i * i)
                exit()
