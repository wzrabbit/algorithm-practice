import sys
input = sys.stdin.readline

d, n = map(int, input().split())
stack = list(map(int, input().split()))
pizza = list(map(int, input().split()))
idx = 0
answer = 0

min_ = stack[0]
for i in range(d):
    if stack[i] > min_:
        stack[i] = min_
    elif stack[i] < min_:
        min_ = stack[i]

while len(stack):
    if stack[-1] >= pizza[idx]:
        idx += 1
    stack.pop()

    if idx == n:
        answer = len(stack) + 1
        break

print(answer)
