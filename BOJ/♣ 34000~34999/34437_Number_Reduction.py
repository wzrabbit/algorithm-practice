N = int(input())
turn = 0

while N > 1:
    turn += 1
    if N % 2 == 0:
        N //= 2
    else:
        N += N * 2 + 1

print(turn)
