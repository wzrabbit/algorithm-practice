import sys
input = sys.stdin.readline
print = sys.stdout.write
INF = 9


def get_path(start, end):
    if history[start][end] != -1:
        get_path(start, history[start][end])
        path.append(history[start][end])
        get_path(history[start][end], end)


T = int(input())
for t in range(1, T + 1):
    E, V = map(int, input().split())
    dist = [[INF] * V for _ in range(V)]
    history = [[-1] * V for _ in range(V)]
    path = []

    for _ in range(E):
        s, e, d = map(int, input().split())
        dist[s][e] = min(dist[s][e], d)
        dist[e][s] = min(dist[e][s], d)

    for m in range(V):
        for s in range(V):
            for e in range(V):
                if dist[s][m] + dist[m][e] < dist[s][e]:
                    dist[s][e] = dist[s][m] + dist[m][e]
                    history[s][e] = m

    print(f'Case #{t}: ')

    if dist[0][V - 1] == INF:
        print('-1\n')
    else:
        path.append(0)
        get_path(0, V - 1)
        path.append(V - 1)

        for i in path:
            print(str(i) + ' ')
        print('\n')
