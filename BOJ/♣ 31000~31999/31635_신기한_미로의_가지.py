import sys

input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush


def traverse(cur, parent):
    global visited_count

    visited[cur] = True
    visited_count += 1

    if cur != 1:
        graph[cur][parent] = True

    while visited_count < N:
        print("maze\n")
        flush()

        result = int(input())

        if visited[result]:
            if result == parent or cur == 1:
                return

            print(f"gaji {cur}\n")
            flush()
            input()
            print(f"gaji {parent}\n")
            flush()
            input()
            return
        else:
            traverse(result, cur)


N = int(input())
graph = [[False] * (N + 1) for _ in range(N + 1)]
visited = [False] * (N + 1)
visited_count = 0

traverse(1, -1)

print("answer\n")

for i in range(1, N + 1):
    for j in range(1, N + 1):
        if graph[i][j]:
            print(f"{i} {j}\n")
flush()
