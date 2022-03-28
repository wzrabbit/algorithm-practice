import sys

while True:
    col, row, amount, range_, no = list(
        map(int, sys.stdin.readline().split(' ')))
    if col == 0 and row == 0 and amount == 0 and range_ == 0 and no == 0:
        break

    land = [[0] * col for i in range(row)]
    firstExplode = {'r': 0, 'c': 0}
    count = 0

    for i in range(amount):
        c, r = list(map(int, sys.stdin.readline().split(' ')))
        c -= 1
        r -= 1
        land[r][c] = 1
        if i == no - 1:
            firstExplode = {'r': r, 'c': c}

    def explode(r, c):
        global count
        land[r][c] = 0
        count += 1

        for i in range(1, range_ + 1):
            if r - i < 0:
                break
            if land[r - i][c] == 1:
                explode(r - i, c)

        for i in range(1, range_ + 1):
            if r + i >= row:
                break
            if land[r + i][c] == 1:
                explode(r + i, c)

        for i in range(1, range_ + 1):
            if c - i < 0:
                break
            if land[r][c - i] == 1:
                explode(r, c - i)

        for i in range(1, range_ + 1):
            if c + i >= col:
                break
            if land[r][c + i] == 1:
                explode(r, c + i)

    explode(firstExplode['r'], firstExplode['c'])
    print(count)
