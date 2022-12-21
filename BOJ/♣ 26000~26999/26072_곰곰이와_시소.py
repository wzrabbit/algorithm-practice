import sys
input = sys.stdin.readline

N, L = map(int, input().split())
pos = list(map(int, input().split()))
weight = list(map(int, input().split()))

start = 0
end = 100000
mid = ''

for i in range(50):
    mid = (start + end) / 2
    score = 0
    for j in range(N):
        score += (pos[j] - mid) * weight[j]
    
    if score > 0:
        start = mid
    else:
        end = mid

print(end)