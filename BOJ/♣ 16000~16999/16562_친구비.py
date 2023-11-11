import sys
from collections import deque

input = sys.stdin.readline

V, E, K = map(int, input().split())
costs = list(map(int, input().split()))
graph = [[] for _ in range(V)]
visited = [False] * V
cost = 0


def get_cheapest_cost(no):
    cheapest_cost = costs[no]
    visited[no] = True
    q = deque()
    q.append(no)

    while len(q) > 0:
        cur = q.popleft()
        cheapest_cost = min(cheapest_cost, costs[cur])

        for n in graph[cur]:
            if not visited[n]:
                visited[n] = True
                q.append(n)

    return cheapest_cost


for i in range(E):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    graph[u].append(v)
    graph[v].append(u)

for i in range(V):
    if not visited[i]:
        cost += get_cheapest_cost(i)

if cost <= K:
    print(cost)
else:
    print("Oh no")
