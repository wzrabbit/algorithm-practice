import sys
import heapq
input = sys.stdin.readline
INF = 10000000

vertex, edge = map(int, input().split())
graph = [[] for i in range(vertex + 1)]

for i in range(edge):
    s, e, t, w = map(int, input().split())
    graph[s].append((e, t, w))

pq = []
heapq.heappush(pq, (0, 1))
dist = [INF] * (vertex + 1)

while len(pq):
    dis, node = heapq.heappop(pq)
    if dis > dist[node]:
        continue

    dist[node] = dis
    for i in range(len(graph[node])):
        e, t, w = graph[node][i]
        next_dist = dis + t
        if dis % w != 0:
            next_dist += w - dis % w

        if next_dist < dist[e]:
            heapq.heappush(pq, (next_dist, e))
            dist[e] = next_dist

print(dist[vertex])
