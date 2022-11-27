R, C = map(int, input().split())
x1, y1 = map(int, input().split())
x2, y2 = map(int, input().split())

if x1 == y1 and x2 == y2:
    print('YES')
elif R == 1 or C == 1:
    print('NO')
elif (x1 + y1) % 2 == (x2 + y2) % 2:
    print('YES')
else:
    print('NO')
