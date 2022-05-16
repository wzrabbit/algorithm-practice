import sys
input = sys.stdin.readline

n, m = map(int, input().split())
c, dir = map(int, input().split())
r = 1
mr, mc = map(int, input().split())
success = True

while not (r == n and c == m):
    if r == mr and c == mc:
        success = False
        break

    if dir == 0:  # <-
        if c == 1:
            r += 1
            dir = 1
        else:
            c -= 1
    else:  # ->
        if c == m:
            r += 1
            dir = 0
        else:
            c += 1

if success:
    print('YES!')
else:
    print('NO...')
