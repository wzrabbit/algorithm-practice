dice = sorted(list(map(int, input().split())))

if dice[0] == dice[1] == dice[2]:
    print(10000 + dice[0] * 1000)
elif dice[0] == dice[1] or dice[1] == dice[2]:
    print(1000 + dice[1] * 100)
else:
    print(dice[2] * 100)
