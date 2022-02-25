import sys
star = int(sys.stdin.readline())
for s in range(1, star + 1):
    print('*' * s + ' ' * (star * 2 - s * 2) + '*' * s)
for s in reversed(range(1, star)):
    print('*' * s + ' ' * (star * 2 - s * 2) + '*' * s)
