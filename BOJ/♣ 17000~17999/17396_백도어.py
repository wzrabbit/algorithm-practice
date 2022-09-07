import sys
import heapq
input = sys.stdin.readline

V, E = map(int, input().split())
INF = 100000 * 100000 + 1
ward = list(map(int, input().split()))
ward[V - 1] = 0
graph = [[] for _ in range(V)]
dist = [INF] * V
pq = []

for _ in range(E):
    s, e, d = map(int, input().split())
    graph[s].append((d, e))
    graph[e].append((d, s))

heapq.heappush(pq, (0, 0))
dist[0] = 0
while len(pq):
    cur_dist, cur_node = heapq.heappop(pq)
    if cur_dist > dist[cur_node]:
        continue

    for next_dist, next_node in graph[cur_node]:
        if cur_dist + next_dist < dist[next_node] and not ward[next_node]:
            dist[next_node] = cur_dist + next_dist
            heapq.heappush(pq, (cur_dist + next_dist, next_node))

if dist[V - 1] == INF:
    print(-1)
else:
    print(dist[V - 1])
