import sys
from collections import deque
input = sys.stdin.readline
row, col = list(map(int, input().split()))
graph = []
for i in range(row):
    graph.append(list(map(str, input().strip())))

startR, startC = 0, 0
for r in range(row):
    for c in range(col):
        if graph[r][c] == 'C':
            startR, startC = r, c

def checkLandExists(r, c, f):
    if f == False:
        while r < row and graph[r][c] != '#' and graph[r][c] != 'D':
            r += 1
        if r == row:
            return -1
        elif graph[r][c] == 'D': # 중력을 바꾸는 도중 D를 만난 경우
            return r
        elif graph[r - 1][c] == '*':
            return -1
        else:
            return r - 1
    else:
        while r >= 0 and graph[r][c] != '#' and graph[r][c] != 'D':
            r -= 1
        if r == -1:
            return -1
        elif graph[r][c] == 'D':
            return r
        elif graph[r + 1][c] == '*':
            return -1
        else:
            return r + 1

def fallBeforeStart():
    global startR
    global startC
    startR = checkLandExists(startR, startC, False)
    if startR == -1:
        return -1
    elif graph[startR][startC] == 'D':
        return 0
    else:
        return 1

def bfs():
    queue = deque([[startR, startC, 0, False]])
    while len(queue):
        r_, c_, d, f = queue.popleft()
        if graph[r_][c_] == 'D':
            return d
        # 좌우로 이동하는 경우
        for i in [-1, 1]:
            r = r_
            c = c_ + i
            if c < col and graph[r][c] != '#':
                r =  checkLandExists(r, c, f)
                if r != -1:
                    if graph[r][c] != 'D':
                        graph[r][c] = '*'
                    queue.appendleft([r, c, d, f])
        # 중력을 바꾸는 경우
        r = checkLandExists(r_, c_, not f)
        c = c_
        if r != -1:
            if graph[r][c] != 'D':
                graph[r][c] = '*'
            queue.append([r, c, d + 1, not f])
    return -1

fall = fallBeforeStart()
if fall == -1:
    print(-1)
elif fall == 0:
    print(0)
else:
    print(bfs())