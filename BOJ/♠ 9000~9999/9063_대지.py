import sys

input = sys.stdin.readline

INF = 123_456
min_x = INF
max_x = -INF
min_y = INF
max_y = -INF

N = int(input())

for _ in range(N):
    x, y = map(int, input().split())
    min_x = min(x, min_x)
    max_x = max(x, max_x)
    min_y = min(y, min_y)
    max_y = max(y, max_y)

print((max_x - min_x) * (max_y - min_y))
