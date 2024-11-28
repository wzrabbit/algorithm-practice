import sys
input = sys.stdin.readline
debug = print
print = sys.stdout.write

X, Y = map(int, input().split())
answer = []
is_X_turn = X >= Y
combo = 0

# 우선 X랑 Y를 같게 만들자
while True:
    # debug(X, Y, combo, is_X_turn)
    if X < 0 or Y < 0:
        print("impossible")
        exit()

    if X == Y:
        break

    if is_X_turn:
        if X - Y == 2 and combo == 0:
            Y -= 1
            X -= 3
            answer.append("U")
            answer.append("R")
            answer.append("R")
            combo = 2
            continue

        if X - Y == 1 and combo == 1:
            X -= 2
            answer.append("R")
            combo = 2
            continue

        next_X = X - 2 ** combo

        if next_X >= Y or (next_X >= 0 and abs(X - Y) > abs(next_X - Y)):
            answer.append("R")
            X = next_X
            combo += 1
        else:
            combo = 1
            Y -= 1
            answer.append("U")
            is_X_turn = False
    else:
        if Y - X == 2 and combo == 0:
            X -= 1
            Y -= 3
            answer.append("R")
            answer.append("U")
            answer.append("U")
            combo = 2
            continue

        if Y - X == 1 and combo == 1:
            Y -= 2
            answer.append("U")
            combo = 2
            continue

        next_Y = Y - 2 ** combo

        if next_Y >= X or (next_Y >= 0 and abs(X - Y) > abs(X - next_Y)):
            answer.append("U")
            Y = next_Y
            combo += 1
        else:
            combo = 1
            X -= 1
            answer.append("R")
            is_X_turn = True

# 그 다음 매 차례마다 무조건 최대한 빼기
Z = X
combo = 0
temp = []
count = len(answer)

while True:
    if Z == 0:
        break

    next_Z = Z - 2 ** combo

    if next_Z == 0:
        temp.append(combo + 1)
        break

    if next_Z < 0:
        temp.append(combo)
        combo = 0
    else:
        Z = next_Z
        combo += 1

print(f'{"".join(answer)}')

for i in temp:
    if is_X_turn:
        print("U" * i + "R" * i)
    else:
        print("R" * i + "U" * i)
    count += i * 2

assert(count <= 4000)
