import sys
input = sys.stdin.readline

limit, station = map(int, input().split())
current = 0
valid = True

for i in range(station):
    minus, plus, wait = map(int, input().split())
    current += plus - minus

    if current < 0 or current > limit:
        valid = False
        break

    if current < limit and wait > 0:
        valid = False
        break

if valid and current == 0:
    print('possible')
else:
    print('impossible')
