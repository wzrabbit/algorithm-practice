import sys
from collections import deque
nodes, water = list(map(int, sys.stdin.readline().split(' ')))
total = 0
leaf = 0
tree = [[] for _ in range(nodes + 1)]
visited = [False] * (nodes + 1)

for _ in range(1, nodes):
    a, b = list(map(int, sys.stdin.readline().split(' ')))
    tree[a].append(b)
    tree[b].append(a)

# BFS
visited[1] = True
queue = deque([[1, water, True]])

while len(queue):
    n, w, r = queue.popleft()
    isLast = True
    for i in range(len(tree[n])):
        nxt = tree[n][i]
        if visited[nxt] == False:
            isLast = False
            visited[nxt] = True
            if r == True:
                visited[nxt] = True
                queue.append([nxt, w / len(tree[n]), False])
            else:
                visited[nxt] = True
                queue.append([nxt, w / (len(tree[n]) - 1), False])

    if isLast == True:
        total += w
        leaf += 1

print(total / leaf)
