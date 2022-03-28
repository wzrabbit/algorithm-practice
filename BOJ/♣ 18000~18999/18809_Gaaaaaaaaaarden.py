import sys
import copy
from collections import deque
row, col, green, red = list(map(int, sys.stdin.readline().split(' ')))
land = []
startLand = []
maxFlowers = 0
a = []

for _ in range(row):
    land.append(list(map(int, sys.stdin.readline().split(' '))))

for r in range(row):
    for c in range(col):
        if land[r][c] == 2:
            startLand.append([r, c])

allNum = len(startLand)
selectNum = green + red
choosed = [False] * allNum
leftColors = {'G': green, 'R': red}

choosedLandList = []
choosedColorList = []


def selectLands(current, arr):
    choosed[current] = True
    arr.append(current)
    if len(arr) == selectNum:
        choosed[current] = False
        choosedLandList.append(arr)
        return
    if allNum - current - 1 < selectNum - len(arr):
        choosed[current] = False
        return
    for i in range(current + 1, allNum):
        if choosed[i] == False:
            selectLands(i, copy.deepcopy(arr))
    choosed[current] = False


def selectColors(current, arr):
    leftColors[current] -= 1
    arr.append(current)
    if len(arr) == selectNum:
        leftColors[current] += 1
        choosedColorList.append(arr)
        return
    if leftColors['G'] > 0:
        selectColors('G', copy.deepcopy(arr))
    if leftColors['R'] > 0:
        selectColors('R', copy.deepcopy(arr))
    leftColors[current] += 1


bbb = 0


def growFlowers(choosedLand, choosedColor):
    visited = [['X'] * col for i in range(row)]
    dr = [-1, 1, 0, 0]
    dc = [0, 0, -1, 1]

    global a
    global bbb

    queue = deque([])
    flowers = 0
    global maxFlowers

    for i in range(len(choosedLand)):
        r, c = startLand[choosedLand[i]]
        if choosedColor[i] == 'G':
            visited[r][c] = 1
            queue.append([r, c, 1])
        else:
            visited[r][c] = -1
            queue.append([r, c, -1])

    while len(queue) != 0:
        r_, c_, t = queue.popleft()
        if visited[r_][c_] == '★':
            continue
        for i in range(4):
            r = r_ + dr[i]
            c = c_ + dc[i]

            if r >= 0 and r < row and c >= 0 and c < col and visited[r_][c_] != '★':
                if land[r][c] == 1 or land[r][c] == 2:
                    if visited[r][c] == 'X':
                        if visited[r_][c_] > 0:
                            visited[r][c] = t + 1
                            queue.append([r, c, t + 1])
                        elif visited[r_][c_] < 0:
                            visited[r][c] = t - 1
                            queue.append([r, c, t - 1])
                    elif visited[r][c] == '★':
                        continue
                    elif (visited[r_][c_] < 0 and visited[r][c] == (t - 1) * -1) or (visited[r_][c_] > 0 and visited[r][c] == (t + 1) * -1):
                        visited[r][c] = '★'
                        flowers += 1

    if flowers > maxFlowers:
        maxFlowers = flowers


for i in range(allNum - selectNum + 1):
    selectLands(i, [])
selectColors('R', [])
selectColors('G', [])

for i in choosedLandList:
    for j in choosedColorList:
        growFlowers(i, j)

print(maxFlowers)
