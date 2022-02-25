import sys
from collections import deque

n = int(sys.stdin.readline())
count = 0
queens = deque([])
cols = [False] * n


def nQueen(r, c):
    global count
    queens.append([r, c])
    cols[c] = True

    for i in range(len(queens)):
        r_, c_ = queens[i]
        if [r_, c_] != [r, c] and (r - c == r_ - c_ or r + c == r_ + c_):
            queens.pop()
            cols[c] = False
            return
    for i in range(n):
        if abs(i - c) >= 2 and cols[i] == False:
            nQueen(r + 1, i)

    if r == n - 1:
        count += 1
    queens.pop()
    cols[c] = False
    return


for i in range(n):
    nQueen(0, i)
print(count)
