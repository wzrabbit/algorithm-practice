import sys
input = sys.stdin.readline

row, col = list(map(int, input().split()))
maze = []
visited = [[0 for j in range(col)] for i in range(row)]
union = [0 for i in range(row * col + 1)]
rank = [1 for i in range(row * col + 1)]
for i in range(row):
    maze.append(list(map(str, input().rstrip())))


def getParent(child):
    if union[child] == 0:
        return child
    union[child] = getParent(union[child])
    return union[child]


def merge(a, b):
    a = getParent(a)
    b = getParent(b)
    if a != b:
        if rank[a] > rank[b]:
            union[b] = a
            rank[a] += rank[b]
        else:
            union[a] = b
            rank[b] += rank[a]


def traverse(r, c):
    no = r * col + c + 1
    while True:
        if visited[r][c] != 0:
            if visited[r][c] != no:
                merge(visited[r][c], no)
            return
        visited[r][c] = no
        if maze[r][c] == 'N':
            r -= 1
        elif maze[r][c] == 'S':
            r += 1
        elif maze[r][c] == 'W':
            c -= 1
        else:
            c += 1


for r in range(row):
    for c in range(col):
        traverse(r, c)

count = 0
for i in range(1, row * col + 1):
    if union[i] == 0:
        count += 1

print(count)
