import sys
from collections import deque
input = sys.stdin.readline

cases = int(input())
board = list(map(int, input().split(' ')))
board = sorted(board, reverse=True)
count = 0
sum_ = 0
minus = 0
total = 0
div = 0

for i in range(cases):
    if board[i] >= 0:
        count += 1
        sum_ += board[i]
        div += 1
    else:
        div = i
        break

for i in range(div, cases):
    if (sum_ + board[i]) * (count + 1) > sum_ * count + board[i]:
        count += 1
        sum_ += board[i]
    else:
        minus += board[i]

total = sum_ * count + minus
print(total)
