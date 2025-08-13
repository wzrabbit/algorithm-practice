import math

T = int(input())

for _ in range(T):
    total, cur, opponent, goal_probability = map(int, input().split())
    remain = total - cur - opponent
    majority = total // 2 + 1
    required = max(0, majority - cur)

    win_probability = 0
    for i in range(required, remain + 1):
        win_probability += math.comb(remain, i)

    win_probability = win_probability * 100 / (2 ** remain)

    if win_probability > goal_probability:
        print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
    elif win_probability == 0:
        print("RECOUNT!")
    else:
        print("PATIENCE, EVERYONE!")
