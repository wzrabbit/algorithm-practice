import sys
import heapq
input = sys.stdin.readline


def dijkstra(ban_s, ban_e, do_hist):
    dist = [INF] * (V + 1)
    pq = [(0, 1)]
    dist[1] = 0

    while len(pq):
        cur_d, cur_v = heapq.heappop(pq)
        if cur_d > dist[cur_v]:
            continue

        for next_d, next_v in graph[cur_v]:
            if ([ban_s, ban_e] != [cur_v, next_v] and [ban_s, ban_e] != [next_v, cur_v] and
                    cur_d + next_d < dist[next_v]):
                dist[next_v] = cur_d + next_d
                heapq.heappush(pq, (cur_d + next_d, next_v))

                if do_hist:
                    history[next_v] = cur_v

    return dist[V]


def traceback(cur):
    if history[cur] != -1:
        traceback(history[cur])
        ban.append((cur, history[cur]))


V, E = map(int, input().split())
INF = 1000001
graph = [[] for _ in range(V + 1)]
history = [-1] * (V + 1)
ban = []

for _ in range(E):
    s, e, d = map(int, input().split())
    graph[s].append((d, e))
    graph[e].append((d, s))

dijkstra(-1, -1, True)
traceback(V)

best = 0
for i in range(len(ban)):
    best = max(best, dijkstra(ban[i][0], ban[i][1], False))

print(best)
