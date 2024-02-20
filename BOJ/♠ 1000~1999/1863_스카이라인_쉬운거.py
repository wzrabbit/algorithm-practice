import sys

input = sys.stdin.readline

N = int(input())
stack = [0]
building_count = 0

for i in range(N):
    height = int(input().split()[1])

    while height < stack[-1]:
        stack.pop()

    if height > stack[-1]:
        stack.append(height)
        building_count += 1

print(building_count)
