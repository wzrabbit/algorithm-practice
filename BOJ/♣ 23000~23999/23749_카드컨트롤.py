import sys
from collections import deque
import copy
input = sys.stdin.readline

cases = int(input())
board = list(map(str, input().strip().split(' ')))

queue = deque([[deque(board), 0]])
while True:
    b, c = queue.popleft()
    s = o = 0
    for i in range(len(board) // 2):
        if b[i * 2] == 'O' and b[i * 2 + 1] == 'X':
            s += 1
        elif b[i * 2] == 'X' and b[i * 2 + 1] == 'O':
            o += 1
    if s > o:
        print(c)
        break

    for i in range(1, len(board)):
        g = copy.deepcopy(b)
        temp = g[i]
        del g[i]
        g.appendleft(temp)
        queue.append([g, c + 1])
