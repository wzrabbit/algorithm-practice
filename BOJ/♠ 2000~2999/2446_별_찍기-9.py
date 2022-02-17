import sys
star = int(sys.stdin.readline())
for s in reversed(range(star)):
    print(' ' * (star - s - 1) + '*' * (s * 2 + 1))
for s in range(1, star):
    print(' ' * (star - s - 1) + '*' * (s * 2 + 1))