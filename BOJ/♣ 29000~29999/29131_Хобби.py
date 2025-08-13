N = int(input())
points = []

for i in range(1, N + 1):
    x, y = map(int, input().split())
    points.append((x, y, i))

points.sort()

print(N // 2)

for i in range(1, N, 2):
    print(points[i - 1][2], points[i][2])
