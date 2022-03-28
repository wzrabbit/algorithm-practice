ax, ay, bx, by = list(map(int, input().split()))
cx, cy, dx, dy = list(map(int, input().split()))


def ccw(ax, ay, bx, by, cx, cy):
    return (bx - ax) * (cy - ay) - (cx - ax) * (by - ay)


if (ccw(ax, ay, bx, by, cx, cy) * ccw(ax, ay, bx, by, dx, dy) == 0 and
        ccw(cx, cy, dx, dy, ax, ay) * ccw(cx, cy, dx, dy, bx, by) == 0):
    if (min(ax, bx) <= max(cx, dx) and min(cx, dx) <= max(ax, bx) and
            min(ay, by) <= max(cy, dy) and min(cy, dy) <= max(ay, by)):
        print(1)
    else:
        print(0)
elif (ccw(ax, ay, bx, by, cx, cy) * ccw(ax, ay, bx, by, dx, dy) <= 0 and
      ccw(cx, cy, dx, dy, ax, ay) * ccw(cx, cy, dx, dy, bx, by) <= 0):
    print(1)
else:
    print(0)
