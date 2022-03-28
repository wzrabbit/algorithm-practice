import sys
input = sys.stdin.readline

row, col = list(map(int, input().split()))
graph = []

for _ in range(row):
    graph.append(list(input().rstrip()))

start = [0, 0]
for r in range(row):
    kill = False
    for c in range(col):
        if graph[r][c] == '#':
            start = [r, c]
            kill = True
            break
    if kill:
        break

r = start[0] + 1
c = start[1] + 1
while graph[r][c] == '.':
    r += 1
    c += 1
end = [r, c]
width = (end[0] - start[0]) // 2
mid = [(start[0] + end[0]) // 2, (start[1] + end[1]) // 2]

if graph[mid[0] - width][mid[1]] == '.':
    print('UP')
elif graph[mid[0] + width][mid[1]] == '.':
    print('DOWN')
elif graph[mid[0]][mid[1] - width] == '.':
    print('LEFT')
else:
    print('RIGHT')
