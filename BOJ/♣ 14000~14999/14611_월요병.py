import sys
import heapq

input = sys.stdin.readline
debug = print
print = sys.stdout.write

R, C = map(int, input().split())
INF = 10 ** 9 * 90000 + 1
dr = (-1, -1, -1, 0, 0, 1, 1, 1)
dc = (-1, 0, 1, -1, 1, -1, 0, 1)
dist = [[INF] * C for _ in range(R)]
grid = []
pq = []

for _ in range(R):
    grid.append(list(map(int, input().split())))

for r in range(R):
    for c in range(C):
        if grid[r][c] == -2:
            grid[r][c] = 0

for r in range(1, R):
    if grid[r][0] != -1:
        dist[r][0] = grid[r][0]
        heapq.heappush(pq, (grid[r][0], r, 0))

for c in range(1, C - 1):
    if grid[R - 1][c] != -1:
        dist[R - 1][c] = grid[R - 1][c]
        heapq.heappush(pq, (grid[R - 1][c], R - 1, c))

while len(pq):
    cur_dist, cur_r, cur_c = heapq.heappop(pq)
    if cur_dist > dist[cur_r][cur_c]:
        continue

    for i in range(8):
        r = cur_r + dr[i]
        c = cur_c + dc[i]

        if 0 <= r < R and 0 <= c < C and grid[r][c] != -1:
            next_dist = dist[r][c]
            if cur_dist + grid[r][c] < dist[r][c]:
                dist[r][c] = cur_dist + grid[r][c]
                heapq.heappush(pq, (dist[r][c], r, c))

best = INF
for c in range(1, C):
    if dist[0][c] < best:
        best = dist[0][c]

for r in range(1, R - 1):
    if dist[r][C - 1] < best:
        best = dist[r][C - 1]

if best == INF:
    print('-1')
else:
    print(f'{best}')
