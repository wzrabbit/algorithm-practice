import sys
import heapq
input = sys.stdin.readline

num, code = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort(key=lambda x: -x)
count = 0
heap = [0] * code

for i in range(num):
    heapq.heappush(heap, heapq.heappop(heap) + arr[i])

print(max(heap))
