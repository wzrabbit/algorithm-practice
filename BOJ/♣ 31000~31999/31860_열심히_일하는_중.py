import heapq
import sys
print = sys.stdout.write

N, M, K = map(int, input().split())
works = []

for _ in range(N):
    cur = int(input())
    heapq.heappush(works, -cur)
    
happiness = [0]

while len(works) > 0:
    cur = -heapq.heappop(works)
    cur_happiness = happiness[-1] // 2 + cur
    happiness.append(cur_happiness)
    cur -= M
    
    if cur > K:
        heapq.heappush(works, -cur)

print(f'{len(happiness) - 1}\n')

for i in range(1, len(happiness)):
    print(f'{happiness[i]}\n')
