import sys
import heapq
input = sys.stdin.readline

N, H, T = map(int, input().split())
heap = []
hammer_use_count = 0

for i in range(N):
    cur = int(input())
    heapq.heappush(heap, -cur)

while True:
    cur_height = heapq.heappop(heap) * -1

    if cur_height < H:
        success = True
        break

    if hammer_use_count == T:
        print('NO')
        print(cur_height)
        exit()

    cur_height //= 2

    if cur_height == 0:
        cur_height = 1

    hammer_use_count += 1
    heapq.heappush(heap, -cur_height)

print('YES')
print(hammer_use_count)
