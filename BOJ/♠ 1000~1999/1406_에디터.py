import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write

left = list(input().strip())  # Stack
right = deque()  # Deque

Q = int(input())
for _ in range(Q):
    com = input().strip().split()

    if com[0] == 'P':
        left.append(com[1])

    elif com[0] == 'L':
        if len(left) > 0:
            right.appendleft(left.pop())

    elif com[0] == 'D':
        if (len(right) > 0):
            left.append(right.popleft())

    else:
        if len(left) > 0:
            left.pop()

print(''.join(left) + ''.join(right))
