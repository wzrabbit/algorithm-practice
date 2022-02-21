import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write
case = int(input())
graph = []
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def fire(row, col):
    queue = deque()
    for r in range(row):
        for c in range(col):
            if graph[r][c] == '*':
                graph[r][c] = 0
                queue.append([r, c, 0])
    while len(queue):
        r_, c_, d = queue.popleft()
        for i in range(4):
            r, c = r_ + dr[i], c_ + dc[i]
            if r >= 0 and r < row and c >= 0 and c < col and graph[r][c] == '.':
                graph[r][c] = d + 1
                queue.append([r, c, d + 1])

def escape(row, col):
    queue = deque()
    found = False
    for r in range(row):
        for c in range(col):
            if graph[r][c] == '@':
                graph[r][c] = 'V'
                queue.append([r, c, 0])
                found = True
                break
        if found:
            break
    while len(queue):
        r_, c_, d = queue.popleft()
        if r_ == 0 or c_ == 0 or r_ == row - 1 or c_ == col - 1:
            return d + 1
        for i in range(4):
            r, c = r_ + dr[i], c_ + dc[i]
            if r >= 0 and r < row and c >= 0 and c < col and graph[r][c] not in ['#', 'V'] and (graph[r][c] == '.' or graph[r][c] > d + 1):
                graph[r][c] = 'V'
                queue.append([r, c, d + 1])
    return 'IMPOSSIBLE'

for i in range(case):
    col, row = list(map(int, input().strip().split(' ')))
    graph = []
    for i in range(row):
        graph.append(list(map(str, input().strip())))
    fire(row, col)
    print(str(escape(row, col)) + '\n')