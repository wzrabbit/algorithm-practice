N, Q = map(int, input().split())


def solve(start, time, plus):
    mul = Q // time
    if Q % time == 0:
        mul -= 1

    return start + plus * mul * (mul + 1) // 2


s, t, p = map(int, input().split())
min_ = solve(s, t, p)
idx = 1

for i in range(N - 1):
    s, t, p = map(int, input().split())
    cur = min(min_, solve(s, t, p))

    if cur < min_:
        min_ = cur
        idx = i + 2

print(idx, min_)
