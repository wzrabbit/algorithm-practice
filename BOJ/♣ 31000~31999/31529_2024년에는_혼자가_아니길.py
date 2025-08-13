X, Y = map(int, input().split())

if X > Y or 2 * X - Y < 0:
    print(-1)
else:
    print((2 * X - Y) * 506)
