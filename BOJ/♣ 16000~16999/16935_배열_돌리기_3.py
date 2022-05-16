import sys
import copy
input = sys.stdin.readline
print = sys.stdout.write

row, col, _ = map(int, input().split())
arr = []
for r in range(row):
    arr.append(list(map(int, input().split())))


def opr1():
    for r in range(row // 2):
        for c in range(col):
            arr[r][c], arr[row - r - 1][c] = arr[row - r - 1][c], arr[r][c]


def opr2():
    for r in range(row):
        for c in range(col // 2):
            arr[r][c], arr[r][col - c - 1] = arr[r][col - c - 1], arr[r][c]


def opr3():
    global arr, row, col
    new_arr = [[] for _ in range(col)]
    for c in range(col):
        for r in reversed(range(row)):
            new_arr[c].append(arr[r][c])
    arr = copy.deepcopy(new_arr)
    row, col = col, row


def opr4():
    global arr, row, col
    new_arr = [[] for _ in range(col)]
    for c in range(col):
        for r in range(row):
            new_arr[col - c - 1].append(arr[r][c])
    arr = copy.deepcopy(new_arr)
    row, col = col, row


def opr5():
    tmp = []
    for r in range(row // 2, row):
        tmp.append(arr[r][:col // 2])
    # 4 -> 3
    for r in range(row // 2, row):
        for c in range(col // 2):
            arr[r][c] = arr[r][c + col // 2]
    # 3 -> 2
    for r in range(row // 2, row):
        for c in range(col // 2, col):
            arr[r][c] = arr[r - row // 2][c]
    # 2 -> 1
    for r in range(row // 2):
        for c in range(col // 2, col):
            arr[r][c] = arr[r][c - col // 2]
    # 1 -> 4
    for r in range(row // 2):
        for c in range(col // 2):
            arr[r][c] = tmp[r][c]


def opr6():
    tmp = []
    for r in range(row // 2, row):
        tmp.append(arr[r][:col // 2])
    # 4 -> 1
    for r in range(row // 2, row):
        for c in range(col // 2):
            arr[r][c] = arr[r - row // 2][c]
    # 1 -> 2
    for r in range(row // 2):
        for c in range(col // 2):
            arr[r][c] = arr[r][c + col // 2]
    # 2 -> 3
    for r in range(row // 2):
        for c in range(col // 2, col):
            arr[r][c] = arr[r + row // 2][c]
    # 3 -> 4
    for r in range(row // 2, row):
        for c in range(col // 2, col):
            arr[r][c] = tmp[r - row // 2][c - col // 2]


query = list(map(int, input().split()))
for q in query:
    if q == 1:
        opr1()
    elif q == 2:
        opr2()
    elif q == 3:
        opr3()
    elif q == 4:
        opr4()
    elif q == 5:
        opr5()
    else:
        opr6()

for r in range(row):
    for c in range(col):
        print(str(arr[r][c]) + ' ')
    print('\n')
