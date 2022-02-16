import sys
from collections import deque
input = sys.stdin.readline

row, col = list(map(int, input().split()))
graph = []
for i in range(row):
    graph.append(list(map(int, input().split())))
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

def getPicArea(startR, startC):
    area = 0
    graph[startR][startC] = 0
    queue = deque([[startR, startC]])
    while len(queue):
        area += 1
        r_, c_ = queue.popleft()
        for d in range(4):
            r, c = r_ + dr[d], c_ + dc[d]
            if r >= 0 and r < row and c >= 0 and c < col and graph[r][c] == 1:
                graph[r][c] = 0
                queue.append([r, c])
    return area

max_ = 0
pictures = 0
for i in range(row):
    for j in range(col):
        if graph[i][j] == 1:
            pictures += 1
            max_ = max(getPicArea(i, j), max_)
print(pictures)
print(max_)