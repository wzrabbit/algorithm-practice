N = int(input())
best = 0

for _ in range(N):
    h, w = map(int, input().split())
    best = max(best, h * w)

print(best)
