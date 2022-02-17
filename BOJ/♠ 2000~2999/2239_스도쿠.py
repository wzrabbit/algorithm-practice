import sys
import copy
input = sys.stdin.readline
print = sys.stdout.write
sudoku = []
kill = False

for _ in range(9):
    sudoku.append(list(map(str, input().strip())))
check = copy.deepcopy(sudoku)

def isFilled(no):
    if no == 81:
        return True
    if check[no // 9][no % 9] == '0':
        return False
    return True

def getRowCol(no):
    return (no // 9, no % 9)

def solveSudoku(no, num):
    global kill
    if kill == True:
        return
    if no == 81:
        for r in range(9):
            for c in range(9):
                print(sudoku[r][c])
            print('\n')
        kill = True
        return
    if num != '-1':
        r, c = getRowCol(no)
        sudoku[r][c] = 'X'
        if num in sudoku[r]:
            sudoku[r][c] = '0'
            return
        elif num in [sudoku[i][c] for i in range(9)]:
            sudoku[r][c] = '0'
            return
        else:
            a, b = r // 3, c // 3
            for i in range(a * 3, a * 3 + 3):
                for j in range(b * 3, b * 3 + 3):
                    if num == sudoku[i][j]:
                        sudoku[r][c] = '0'
                        return
        sudoku[r][c] = num
    if isFilled(no + 1):
        solveSudoku(no + 1,'-1')
    else:
        for i in range(1, 10):
            if kill == True:
                break
            solveSudoku(no + 1, str(i))
    if num != '-1':
        sudoku[r][c] = '0'

if check[0][0] == '0':
    for i in range(9):
        solveSudoku(0, str(i))
else:
    solveSudoku(0, '-1')