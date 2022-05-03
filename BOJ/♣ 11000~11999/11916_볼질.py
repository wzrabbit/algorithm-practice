import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int, input().split()))
field = [False, False, False, False]
score = 0
ball = 0


def ball4():
    global score
    global ball

    if field[1:] == [True, True, True]:
        field[3] = False
        score += 1
    if field[2] == True and field[1] == True:
        field[2] = False
        field[3] = True
    if field[1] == True:
        field[1] = False
        field[2] = True
    field[1] = True

    ball = 0


def poktu(hitter_run):
    global score
    global ball

    if field[3] == True:
        field[3] = False
        score += 1
    if field[2] == True:
        field[2] = False
        field[3] = True
    if field[1] == True:
        field[1] = False
        field[2] = True
    if hitter_run:
        field[1] = True

    if hitter_run:
        ball = 0


for i in arr:
    if i == 1:
        ball += 1
        if ball == 4:
            ball4()
    elif i == 2:
        ball4()
    else:
        ball += 1
        if ball == 4:
            poktu(True)
        else:
            poktu(False)

print(score)
