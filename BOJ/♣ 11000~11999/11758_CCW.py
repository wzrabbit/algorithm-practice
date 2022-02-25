import sys
t = []
for _ in range(3):
    t.append(tuple(map(int, sys.stdin.readline().split(' '))))

# CCW
ccw = (t[1][0] - t[0][0]) * (t[2][1] - t[0][1]) - \
    (t[2][0] - t[0][0]) * (t[1][1] - t[0][1])
if ccw > 0:
    print(1)
elif ccw < 0:
    print(-1)
else:
    print(0)
