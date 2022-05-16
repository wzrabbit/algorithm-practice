import sys
input = sys.stdin.readline
print = sys.stdout.write

basket, ball = map(int, input().split())
board = [0] * (basket + 1)

for _ in range(ball):
    s, e, b = map(int, input().split())
    for i in range(s, e + 1):
        board[i] = b

for i in range(1, basket + 1):
    print(str(board[i]) + ' ')
