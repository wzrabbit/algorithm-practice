import sys
from collections import deque
import copy
nodes, cases = list(map(int, sys.stdin.readline().split()))
tree = [[] for _ in range(nodes + 1)]
distTree = [[] for _ in range(nodes + 1)]
visitedSample = [False] * (nodes + 1)

for _ in range(nodes - 1):
    a, b, d = list(map(int, sys.stdin.readline().split()))
    tree[a].append(b)
    tree[b].append(a)
    distTree[a].append(d)
    distTree[b].append(d)


def bfs(start, end, visited):
    queue = deque([[start, 0]])
    while len(queue):
        node, dist = queue.popleft()
        if node == end:
            print(dist)
            return
        for i in range(len(tree[node])):
            nxt = tree[node][i]
            nxtDist = distTree[node][i]
            if visited[nxt] == False:
                visited[nxt] = True
                queue.append([nxt, dist + nxtDist])
    print('fail')


for _ in range(cases):
    s, e = list(map(int, sys.stdin.readline().split()))
    bfs(s, e, copy.deepcopy(visitedSample))
