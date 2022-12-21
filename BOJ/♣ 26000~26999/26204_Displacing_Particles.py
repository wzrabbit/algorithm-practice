N, x, y = map(int, input().split())
x_gap = abs(2 ** N // 2 - x)
y_gap = abs(2 ** N // 2 - y)

x_moves = bin(x_gap)[2:].zfill(N - 1).rfind('1') + 1
y_moves = bin(y_gap)[2:].zfill(N - 1).rfind('1') + 1

print(min(x_moves, y_moves))
