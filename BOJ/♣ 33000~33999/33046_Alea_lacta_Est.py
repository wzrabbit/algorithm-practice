a1, a2 = map(int, input().split())
b1, b2 = map(int, input().split())
start = 0

start += a1 + a2 + b1 + b2 - 2
start %= 4

print(start + 1)
