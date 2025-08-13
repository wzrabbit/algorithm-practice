board = []

for _ in range(2):
    board.append(input())

cw = (board[0][0] + board[0][1] + board[1][1] + board[1][0]) * 2
ccw = (board[0][0] + board[1][0] + board[1][1] + board[0][1]) * 2

if "HEPC" in cw or "HEPC" in ccw:
    print("YES")
else:
    print("NO")
