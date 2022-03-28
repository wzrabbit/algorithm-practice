import sys
cases = int(sys.stdin.readline())
nodes = list(map(int, sys.stdin.readline().split(' ')))
visited = [-1] * (max(nodes) + 1)
stack = []

for n in nodes:
    if len(stack) >= 2 and stack[-2] == n:
        stack.pop()
    elif len(stack) >= 1:
        visited[n] = stack[-1]
        stack.append(n)
    else:
        stack.append(n)

print(len(visited))
print(' '.join([str(i) for i in visited]))
