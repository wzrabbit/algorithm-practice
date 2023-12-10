N = int(input())
max_y = -(10**9)
min_y = 10**9

for _ in range(N):
    y = int(input().split()[1])
    max_y = max(max_y, y)
    min_y = min(min_y, y)

print(max_y - min_y)
