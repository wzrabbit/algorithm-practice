import sys
from collections import deque
input = sys.stdin.readline


def ward(a, b, l):
    queue = deque([[a, b]])
    visited[a][b] = True
    sight[a][b] = '.'

    while len(queue) > 0:
        r_, c_ = queue.popleft()
        for i in range(4):
            r = r_ + dr[i]
            c = c_ + dc[i]
            if r >= 0 and c >= 0 and r < row and c < col and graph[r][c] == l and visited[r][c] == False:
                visited[r][c] = True
                sight[r][c] = '.'
                queue.append([r, c])


def move(command):
    global hr, hc
    if command == 'L':
        hc -= 1
    elif command == 'R':
        hc += 1
    elif command == 'U':
        hr -= 1
    elif command == 'D':
        hr += 1
    else:
        ward(hr, hc, graph[hr][hc])


row, col = map(int, input().split(' '))
graph = []
visited = [[False for c in range(col)] for r in range(row)]
sight = [['#' for c in range(col)] for r in range(row)]
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
for i in range(row):
    graph.append(list(input().strip()))

hr, hc = map(int, input().split(' '))
hr -= 1
hc -= 1
commands = list(input().strip())
for i in range(len(commands)):
    move(commands[i])

sight[hr][hc] = '.'
for i in range(4):
    r = hr + dr[i]
    c = hc + dc[i]
    if r >= 0 and c >= 0 and r < row and c < col:
        sight[r][c] = '.'

for i in range(row):
    sight[i] = ''.join(sight[i])
print('\n'.join(sight))
