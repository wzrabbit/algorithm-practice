n = int(input())
dot = []
inf = 1000000
previous = [-1] * 5000
answer = [inf] * n

for _ in range(n):
    dot.append(tuple(map(int, input().split())))
dot.sort(key=lambda x: x[0])

for i in range(n):
    pos, color = dot[i]

    if previous[color] != -1:
        answer[i] = pos - previous[color]

    previous[color] = pos

previous = [-1] * 5000
for i in reversed(range(n)):
    pos, color = dot[i]

    if previous[color] != -1:
        answer[i] = min(answer[i], previous[color] - pos)

    previous[color] = pos

print(answer)
print(sum(answer))
