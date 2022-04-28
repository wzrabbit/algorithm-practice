import sys
input = sys.stdin.readline
graph = []


def check(row, col, width):
    for r in range(row, row + width):
        for c in range(col, col + width):
            if graph[r][c] == '#':
                return False
    return True


def process():
    for w in reversed(range(1, n + 1)):
        for r in range(n - w + 1):
            for c in range(n - w + 1):
                if check(r, c, w):
                    print(w)
                    return
    print(0)


t = int(input())
for _ in range(t):
    n = int(input())
    graph = []
    kill = False
    for _ in range(n):
        graph.append(list(input().strip()))

    process()
