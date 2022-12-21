import sys
from collections import deque
input = sys.stdin.readline
print = sys.stdout.write


def is_possible():
    for r in range(R):
        combo = 0
        for c in range(C):
            if wall[r][c] == 1:
                combo += 1
            else:
                combo = 0

            if combo > color:
                return False

    for c in range(C):
        combo = 0
        for r in range(R):
            if wall[r][c] == 1:
                combo += 1
            else:
                combo = 0

            if combo > color:
                return False

    return True


def paint():
    for r in range(R):
        brush = r % color
        for c in range(C):
            if wall[r][c] == 1:
                painted[r][c] = brush + 1
            brush = (brush + 1) % color


T = int(input())
for _ in range(T):
    R, C, color = map(int, input().split())
    wall = []
    painted = [[0] * C for __ in range(R)]
    for __ in range(R):
        wall.append(list(map(int, input().split())))
    success = True

    if is_possible():
        paint()
        print('YES\n')
        for r in range(R):
            for c in range(C):
                print(f'{painted[r][c]} ')
            print('\n')
    else:
        print('NO\n')
