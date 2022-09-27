import sys
import heapq
input = sys.stdin.readline

N, K = map(int, input().split())
lake = list(map(int, input().split()))
lake.sort()
total_cost = 0
pq = []

for i in range(N - 1):
    heapq.heappush(pq, (2, lake[i + 1] - lake[i] - 1))
heapq.heappush(pq, (2, 10 ** 10))

while K > 0:
    cost, left = heapq.heappop(pq)
    if left == 0:
        continue

    total_cost += cost // 2
    left -= 1
    cost += 1
    K -= 1

    if left >= 1:
        heapq.heappush(pq, (cost, left))

print(total_cost)
