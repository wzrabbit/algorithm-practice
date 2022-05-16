import sys
import heapq
input = sys.stdin.readline
print = sys.stdout.write

dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
INF = 200000
no = 1

while True:
    N = int(input())
    if N == 0:
        break

    cave = []
    pq = []
    dist = [[INF for j in range(N)] for i in range(N)]
    for _ in range(N):
        cave.append(list(map(int, input().split())))
    heapq.heappush(pq, (cave[0][0], 0, 0))
    dist[0][0] = cave[0][0]

    while len(pq):
        dis, row, col = heapq.heappop(pq)
        if dis > dist[row][col]:
            continue

        for i in range(4):
            r = row + dr[i]
            c = col + dc[i]

            if 0 <= r < N and 0 <= c < N and dis + cave[r][c] < dist[r][c]:
                heapq.heappush(pq, (dis + cave[r][c], r, c))
                dist[r][c] = dis + cave[r][c]

    print(str('Problem {}: {}\n').format(no, dist[N - 1][N - 1]))
    no += 1
