amount = int(input())
dir = [0] * 6
dist = [0] * 6
curve = 0
base = 0

for i in range(6):
    dir[i], dist[i] = map(int, input().split())
dir *= 2
dist *= 2

for i in range(6):
    if dir[i] == dir[i + 2] and dir[i + 1] == dir[i + 3]:
        curve = i + 1
        base = i + 4

print((dist[base] * dist[base + 1] - dist[curve] * dist[curve + 1]) * amount)
