import sys
input = sys.stdin.readline
print = sys.stdout.write

n = int(input())
height = list(map(int, input().split()))
stack = []

for i in range(n):
    while len(stack) > 0 and height[stack[-1]] < height[i]:
        stack.pop()
    if len(stack) == 0:
        print('0 ')
    else:
        print(str(stack[-1] + 1) + ' ')
    stack.append(i)