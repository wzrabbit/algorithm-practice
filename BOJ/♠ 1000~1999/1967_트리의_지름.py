import sys
from collections import deque
import copy
nodes = int(sys.stdin.readline())
tree = [[] for _ in range(nodes + 1)]
distTree = [[] for _ in range(nodes + 1)]
totalMax = 0

for _ in range(nodes - 1):
    a, b, d = list(map(int, sys.stdin.readline().split()))
    tree[a].append(b)
    distTree[a].append(d)

def bfs(start, startDist):
    maxDist = 0
    queue = deque([[start, startDist]])
    while len(queue):
        node, dist = queue.popleft()
        isLeaf = True
        for i in range(len(tree[node])):
            nxt = tree[node][i]
            nxtDist = distTree[node][i]
            isLeaf = False
            queue.append([nxt, dist + nxtDist])
        if isLeaf and dist > maxDist:
            maxDist = dist
    return maxDist

for i in range(1, nodes + 1):
    current = 0
    maxLen = 0
    maxLen2 = 0
    for j in range(len(tree[i])):
        current = bfs(tree[i][j], distTree[i][j])
        if current > maxLen:
            maxLen2 = maxLen
            maxLen = current
        elif current > maxLen2:
            maxLen2 = current
    if maxLen + maxLen2 > totalMax:
        totalMax = maxLen + maxLen2

print(totalMax)