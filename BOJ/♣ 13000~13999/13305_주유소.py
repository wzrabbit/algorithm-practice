import sys
input = sys.stdin.readline

N = int(input())
dist = list(map(int, input().split()))
cost = list(map(int, input().split()))
best = 1000000001
ans = 0

for i in range(N - 1):
    best = min(best, cost[i])
    ans += best * dist[i]

print(ans)
