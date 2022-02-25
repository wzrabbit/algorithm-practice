import sys
from collections import deque
nodes = int(sys.stdin.readline())
tree = [[] for _ in range(nodes + 1)]
distTree = [[] for _ in range(nodes + 1)]
visited = [False] * (nodes + 1)
totalMax = 0

for _ in range(nodes):
    line = list(map(int, sys.stdin.readline().split()))
    a = line[0]
    for i in range(int((len(line) - 2) / 2)):
        b = line[i * 2 + 1]
        d = line[i * 2 + 2]
        tree[a].append(b)
        distTree[a].append(d)


def bfs(start):
    queue = deque([[start, 0]])
    visited[start] = True
    mx = 0
    mxNode = 0
    while len(queue):
        last = True
        node, dist = queue.popleft()
        for i in range(len(tree[node])):
            nxt = tree[node][i]
            nxtDist = distTree[node][i]
            if visited[nxt] == False:
                last = False
                visited[nxt] = True
                queue.append([nxt, dist + nxtDist])
        if last and dist > mx:
            mx = dist
            mxNode = node
    return [mx, mxNode]


far = bfs(1)[1]
visited = [False] * (nodes + 1)
result = bfs(far)[0]
print(result)
