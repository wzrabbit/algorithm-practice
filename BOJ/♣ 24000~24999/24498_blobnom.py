import sys
input = sys.stdin.readline
n = int(input())
tower = list(map(int, input().split()))
max_ = max(tower[0], tower[-1])

for i in range(1, n - 1):
    current = min(tower[i - 1], tower[i + 1]) + tower[i]
    if max_ < current:
        max_ = current

print(max_)
