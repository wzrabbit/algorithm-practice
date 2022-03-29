import sys
input = sys.stdin.readline

n = int(input())
building = [0]
for i in range(n):
    building.append(int(input()))
building.append(1000000001)

stack = [0]
total = 0
for i in range(1, n + 2):
    while len(stack) > 0 and building[stack[-1]] <= building[i]:
        total += i - stack.pop() - 1
    stack.append(i)

print(total)
