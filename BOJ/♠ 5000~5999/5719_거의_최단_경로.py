import sys
import heapq
from collections import deque
input = sys.stdin.readline
debug = print
print = sys.stdout.write
INF = 500001


def dijkstra():
    pq = []
    heapq.heappush(pq, (0, start))
    dist[start] = 0

    while len(pq):
        cur_d, cur_v = heapq.heappop(pq)
        if cur_d > dist[cur_v]:
            continue

        for next_d, next_v in graph[cur_v]:
            if cur_d + next_d == dist[next_v] and not ban[cur_v][next_v]:
                prev[next_v].append(cur_v)

            elif cur_d + next_d < dist[next_v] and not ban[cur_v][next_v]:
                dist[next_v] = cur_d + next_d
                prev[next_v] = [cur_v]
                heapq.heappush(pq, (cur_d + next_d, next_v))


def bfs(start):
    q = deque()
    q.append(start)
    visited[start] = True

    while q:
        cur = q.popleft()
        for nxt in prev[cur]:
            ban[nxt][cur] = True

            if not visited[nxt]:
                visited[nxt] = True
                q.append(nxt)


while True:
    V, E = map(int, input().split())
    if V == E == 0:
        break

    start, end = map(int, input().split())
    graph = [[] for _ in range(V)]
    prev = [[] for _ in range(V)]
    ban = [[False] * V for _ in range(V)]
    dist = [INF] * V
    visited = [False] * V

    for _ in range(E):
        s, e, d = map(int, input().split())
        graph[s].append((d, e))

    dijkstra()
    bfs(end)
    dist = [INF] * V
    dijkstra()

    if dist[end] == INF:
        print('-1\n')
    else:
        print(f'{dist[end]}\n')
