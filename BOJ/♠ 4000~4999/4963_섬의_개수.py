import sys
from collections import deque
input = sys.stdin.readline
graph = ''
visited = ''
col = ''
row = ''
dr = (-1, 1, 0, 0, -1, -1, 1, 1)
dc = (0, 0, -1, 1, -1, 1, -1, 1)


def bfs(start_row, start_col):
    que = deque()
    que.append((start_row, start_col))

    while len(que):
        ro, co = que.pop()

        for i in range(8):
            r = ro + dr[i]
            c = co + dc[i]

            if 0 <= r < row and 0 <= c < col and visited[r][c] == False and graph[r][c] == 1:
                visited[r][c] = True
                que.append((r, c))


while True:
    col, row = map(int, input().split())
    if col == 0 and row == 0:
        break

    graph = []
    visited = [[False for c in range(col)] for r in range(row)]
    island = 0

    for _ in range(row):
        graph.append(list(map(int, input().split())))

    for r in range(row):
        for c in range(col):
            if visited[r][c] == False and graph[r][c] == 1:
                bfs(r, c)
                island += 1

    print(island)
