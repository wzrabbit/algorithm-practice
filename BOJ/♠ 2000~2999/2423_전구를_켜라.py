import sys
from collections import deque
input = sys.stdin.readline

def toggle(arg):
    if arg == '\\':
        return '/'
    else:
        return '\\'
    
def bfs():
    queue = deque()
    dr = [-1, 1, 0, 0, -1, 1, 1, -1]
    dc = [0, 0, -1, 1, -1, 1, -1, 1]
    visited[0][0] = True
    if graph[0][0] == '\\':
        queue.append([0, 0, 0, '\\'])
    else:
        queue.append([0, 0, 1, '\\'])

    while len(queue) > 0:
        r_, c_, p, h = queue.popleft()
        if r_ == row - 1 and c_ == col - 1:
            if h == '\\':
                print(p)
            else:
                print('NO SOLUTION')
            return
        for i in range(8):
            r = r_ + dr[i]
            c = c_ + dc[i]
            if r >= 0 and r < row and c >= 0 and c < col and visited[r][c] == False:
                if i < 4:
                    visited[r][c] = True
                    if graph[r][c] != h:
                        queue.appendleft([r, c, p, toggle(h)])
                        #print([[r_, c_, p, h], [r, c, p, toggle(h)]])
                    else:
                        queue.append([r, c, p + 1, toggle(h)])
                        #print([[r_, c_, p, h], [r, c, p + 1, toggle(h)]])
                elif i == 4 or i == 5:
                    if h == '\\':
                        if graph[r][c] == '\\':
                            visited[r][c] = True
                            queue.appendleft([r, c, p, h])
                        else:
                            visited[r][c] = True
                            queue.append([r, c, p + 1, h])
                else:
                    if h == '/':
                        if graph[r][c] == '/':
                            visited[r][c] = True
                            queue.appendleft([r, c, p, h])
                        else:
                            visited[r][c] = True
                            queue.append([r, c, p + 1, h])

row, col = list(map(int, input().split(' ')))
visited = [[False for j in range(col)] for i in range(row)]
graph = []
for _ in range(row):
    graph.append(list(input().strip()))
bfs()