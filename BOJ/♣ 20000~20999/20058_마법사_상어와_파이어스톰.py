import sys
from collections import deque
input = sys.stdin.readline


def spin(start_row, start_col, lv):
    temp = []
    s1 = start_row
    s2 = s1 + lv ** 2
    e1 = start_col
    e2 = e1 + lv ** 2

    for r in range(start_row, s2):
        temp.append(temp[r][start_col:start_col + lv ** 2])

    for r in range(start_row, s2):
        for c in range(start_col, start_col + lv ** 2):
            board[r][c] = board[]


n, q = map(int, input().split())
board = []
for _ in range(n):
    board.append(list(map(int, input().split())))
step = list(map(int, input().split()))
