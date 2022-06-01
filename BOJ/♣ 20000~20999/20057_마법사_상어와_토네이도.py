import sys
input = sys.stdin.readline

dwr = (
    (-2, -1, -1, 0, 0, 0, 0, 1, 1, -1),
    (0, -1, 1, -2, -1, 1, 2, -1, 1, 0),
    (2, 1, 1, 0, 0, 0, 0, -1, -1, 1),
    (0, 1, -1, 2, 1, -1, -2, 1, -1, 0)
)
dwc = (
    (0, -1, 1, -2, -1, 1, 2, -1, 1, 0),
    (2, 1, 1, 0, 0, 0, 0, -1, -1, 1),
    (0, 1, -1, 2, 1, -1, -2, 1, -1, 0),
    (-2, -1, -1, 0, 0, 0, 0, 1, 1, -1)
)
per = (5, 10, 10, 2, 7, 7, 2, 1, 1, 0)
dr = (-1, 0, 1, 0)
dc = (0, 1, 0, -1)


def move(row, col, pos):
    sand = board[row][col]
    left = sand
    out = 0

    for i in range(10):
        r = row + dwr[pos][i]
        c = col + dwc[pos][i]
        value = sand * per[i] // 100

        if i == 9:
            value = left

        if r >= 0 and r < n and c >= 0 and c < n:
            board[r][c] += value
        else:
            out += value
        left -= value

    board[row][col] = 0
    return out


n = int(input())
board = []
pos = 3
row, col = n - n // 2 - 1, n - n // 2 - 1
power = 2
out = 0
for _ in range(n):
    board.append(list(map(int, input().split())))

while True:
    kill = False
    for i in range(power // 2):
        row += dr[pos]
        col += dc[pos]
        out += move(row, col, pos)

        if row == 0 and col == 0:
            kill = True
            break

    if kill:
        break

    pos = (pos - 1) % 4
    power += 1

print(out)
