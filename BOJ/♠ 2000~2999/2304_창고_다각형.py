import sys
pillars = int(sys.stdin.readline())
board = [0] * 1000
height = [0] * 1000

for _ in range(pillars):
    p, h = list(map(int, sys.stdin.readline().split(' ')))
    p -= 1
    board[p] = h

max_ = 0
for i in range(1000):
    if board[i] > max_:
        max_ = board[i]
    height[i] = max_

max_ = 0
for i in reversed(range(1000)):
    if board[i] > max_:
        max_ = board[i]
    height[i] = min(max_, height[i])

total = 0
for i in range(1000):
    total += height[i]
print(total)