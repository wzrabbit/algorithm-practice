import sys
input = sys.stdin.readline

width = int(input())
height = width
count = 1
while height > 1:
    height //= 2
    count += 1
height = count

grid = [[0 for j in range(width)] for i in range(height)]
tree = list(map(int, input().split()))
count = 0
allMinus = True
minusMax = - (10 ** 9)


def traverse(node, level):
    global count
    global allMinus
    global minusMax
    if level == height - 1:
        grid[level][count] = tree[node]
        count += 1
        if tree[node] >= 0:
            allMinus = False
        if tree[node] > minusMax:
            minusMax = tree[node]
    else:
        traverse(node * 2 + 1, level + 1)
        grid[level][count] = tree[node]
        count += 1
        if tree[node] >= 0:
            allMinus = False
        if tree[node] > minusMax:
            minusMax = tree[node]
        traverse(node * 2 + 2, level + 1)


traverse(0, 0)

finalMax = - (10 ** 11)
for r in range(1, height):
    for c in range(width):
        grid[r][c] += grid[r - 1][c]

for t in range(0, height):
    for b in range(t, height):
        max_ = 0
        sum_ = 0
        if t == 0:
            for i in range(width):
                sum_ += grid[b][i]
                if sum_ > max_:
                    max_ = sum_
                if sum_ < 0:
                    sum_ = 0
        else:
            for i in range(width):
                sum_ += grid[b][i] - grid[t - 1][i]
                if sum_ > max_:
                    max_ = sum_
                if sum_ < 0:
                    sum_ = 0
        if max_ > finalMax:
            finalMax = max_

if allMinus == True:
    print(minusMax)
else:
    print(finalMax)
