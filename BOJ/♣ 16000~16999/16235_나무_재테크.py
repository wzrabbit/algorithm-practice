import sys
input = sys.stdin.readline
width, tree, year = list(map(int, input().split()))
trees = [[[] for j in range(width)] for i in range(width)]
land = [[5 for j in range(width)] for i in range(width)]
plus = []
dr = [-1, 1, 0, 0, -1, 1, -1, 1]
dc = [0, 0, -1, 1, -1, 1, 1, -1]

for i in range(width):
    plus.append(list(map(int, input().split())))

for i in range(tree):
    r, c, a = list(map(int, input().split()))
    trees[r - 1][c - 1].append(a)


def springSummer():
    for r in range(width):
        for c in range(width):
            trees[r][c].sort()
            task = len(trees[r][c])
            for i in range(len(trees[r][c])):
                if land[r][c] >= trees[r][c][i]:
                    land[r][c] -= trees[r][c][i]
                    trees[r][c][i] += 1
                else:
                    for j in range(i, task):
                        land[r][c] += trees[r][c][j] // 2
                    del trees[r][c][i:task]
                    break


def autumnWinter():
    for r0 in range(width):
        for c0 in range(width):
            for i in range(len(trees[r0][c0])):
                if trees[r0][c0][i] % 5 == 0:
                    for j in range(8):
                        r = r0 + dr[j]
                        c = c0 + dc[j]
                        if r >= 0 and r < width and c >= 0 and c < width:
                            trees[r][c].append(1)
    for r in range(width):
        for c in range(width):
            land[r][c] += plus[r][c]


for y in range(year):
    springSummer()
    autumnWinter()
result = 0
for r in range(width):
    for c in range(width):
        result += len(trees[r][c])

print(result)
