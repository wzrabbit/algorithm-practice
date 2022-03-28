import sys
nodes = int(sys.stdin.readline())
graph = [[] for i in range(nodes + 1)]
visited = [False] * (nodes + 1)

for _ in range(nodes - 1):
    a, b = list(map(int, sys.stdin.readline().split(' ')))
    graph[a].append(b)
    graph[b].append(a)

order = list(map(int, sys.stdin.readline().split(' ')))


def dfs():
    index = 1
    stack = [1]
    visited[1] = True
    while len(stack) and index != nodes:
        current = stack[-1]
        if len(graph[current]) == 0:
            stack.pop()
        elif order[index] in graph[current]:
            stack.append(order[index])
            visited[order[index]] = True
            index += 1
        else:
            for i in graph[current]:
                if visited[i] == False:
                    return 0
            stack.pop()
    if index != nodes:
        return 0
    else:
        return 1


if order[0] == 1:
    print(dfs())
else:
    print(0)
