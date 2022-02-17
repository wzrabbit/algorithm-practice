import sys
star = int(sys.stdin.readline())
for s in reversed(range(1, star + 1)):
    print('*' * s)