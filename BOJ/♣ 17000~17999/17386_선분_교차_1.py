ax, ay, bx, by = list(map(int, input().split()))
cx, cy, dx, dy = list(map(int, input().split()))


def ccw(ax, ay, bx, by, cx, cy):
    return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay)


if ccw(ax, ay, bx, by, cx, cy) * ccw(ax, ay, bx, by, dx, dy) < 0:
    if ccw(cx, cy, dx, dy, ax, ay) * ccw(cx, cy, dx, dy, bx, by) < 0:
        print(1)
    else:
        print(0)
else:
    print(0)
