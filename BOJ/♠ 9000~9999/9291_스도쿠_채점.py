T = int(input())
for t in range(1, T + 1):
    sudoku = []
    success = True

    for _ in range(9):
        sudoku.append(list(map(int, input().split())))

    if t != T:
        input()

    for r in range(9):
        checker = [False] * 10

        for c in range(9):
            checker[sudoku[r][c]] = True

        if False in checker[1:]:
            success = False

    for c in range(9):
        checker = [False] * 10

        for r in range(9):
            checker[sudoku[r][c]] = True

        if False in checker[1:]:
            success = False

    for i in range(0, 9, 3):
        for j in range(0, 9, 3):
            checker = [False] * 10

            for r in range(i, i + 3):
                for c in range(j, j + 3):
                    checker[sudoku[r][c]] = True

            if False in checker[1:]:
                success = False

    print(f'Case {t}: {"CORRECT" if success else "INCORRECT"}')
