N = int(input())
best = 999

for _ in range(N):
    A, B = map(int, input().split())
    best = min(A + B, best)

print(best)
