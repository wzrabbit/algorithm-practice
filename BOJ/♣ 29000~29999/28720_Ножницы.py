R, C = map(int, input().split())
repeat = min(R, C) - 1

print(repeat * (2 * R - repeat - 1) // 2 + repeat * (2 * C - repeat - 3) // 2)
