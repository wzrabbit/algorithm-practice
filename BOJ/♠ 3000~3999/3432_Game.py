import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    board = []
    for __ in range(5):
        board.append(list(input().strip()))

    a_win = False
    b_win = False

    # 가로 3칸
    for r in range(5):
        for c in range(3):
            text = board[r][c] + board[r][c + 1] + board[r][c + 2]
            if text == 'AAA':
                a_win = True
            elif text == 'BBB':
                b_win = True

    # 세로 3칸
    for r in range(3):
        for c in range(5):
            text = board[r][c] + board[r + 1][c] + board[r + 2][c]
            if text == 'AAA':
                a_win = True
            elif text == 'BBB':
                b_win = True

    # 왼쪽 대각선 3칸
    for r in range(3):
        for c in range(2, 5):
            text = board[r][c] + board[r + 1][c - 1] + board[r + 2][c - 2]
            if text == 'AAA':
                a_win = True
            elif text == 'BBB':
                b_win = True

    # 오른쪽 대각선 3칸
    for r in range(3):
        for c in range(3):
            text = board[r][c] + board[r + 1][c + 1] + board[r + 2][c + 2]
            if text == 'AAA':
                a_win = True
            elif text == 'BBB':
                b_win = True

    if a_win and not b_win:
        print('A wins\n')
    elif not a_win and b_win:
        print('B wins\n')
    else:
        print('draw\n')
