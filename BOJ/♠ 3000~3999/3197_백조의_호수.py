import sys
import copy
from collections import deque

input = sys.stdin.readline
row, col = list(map(int, input().split()))
graph = []
dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]
swan = [0, 0]
queue = deque([])
tempQueue = deque([])
time = 0
foundSwan = False
for i in range(row):
    graph.append(list(map(str, input().strip())))

for r in range(row):
    for c in range(col):
        if graph[r][c] == 'X':
            for i in range(4):
                r_ = r + dr[i]
                c_ = c + dc[i]
                if r_ >= 0 and r_ < row and c_ >= 0 and c_ < col and graph[r_][c_] in ['.', 'L']:
                    graph[r][c] = 1
                    queue.append([r, c, 1])
                    break
        elif graph[r][c] == 'L':
            swan = [r, c]
            
while len(queue):
    r, c, t = queue.popleft()
    for i in range(4):
        r_ = r + dr[i]
        c_ = c + dc[i]
        if r_ >= 0 and r_ < row and c_ >= 0 and c_ < col and graph[r_][c_] == 'X':
            graph[r_][c_] = t + 1
            queue.append([r_, c_, t + 1])

queue.append(swan)
graph[swan[0]][swan[1]] = '*'
while not foundSwan:
    while len(queue):
        r, c = queue.popleft()
        if graph[r][c] == 'L':
            print(time)
            foundSwan = True
            break
        isStuck = True
        stuckReason = []
        for i in range(4):
            r_ = r + dr[i]
            c_ = c + dc[i]
            if r_ >= 0 and r_ < row and c_ >= 0 and c_ < col:
                if graph[r_][c_] in ['.', 'L'] or (type(graph[r_][c_]) == int and graph[r_][c_] <= time):
                    isStuck = False
                    if graph[r_][c_] != 'L':
                        graph[r_][c_] = '*'
                    queue.append([r_, c_])
                else:
                    stuckReason.append(graph[r_][c_])
        if isStuck:
            for i in range(len(stuckReason)):
                if type(stuckReason[i]) == int:
                    tempQueue.append([r, c])
                    break
    if not foundSwan:
        time += 1
        queue = copy.deepcopy(tempQueue)
        tempQueue = deque([])