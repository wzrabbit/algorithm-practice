T = int(input())
for _ in range(T):
    game = list(map(int, input().split()))
    X, Y = 1, game[-1]
    is_X = True

    for i in reversed(range(1, len(game) - 1)):
        if is_X:
            X += game[i] * Y
        else:
            Y += game[i] * X

        is_X = not is_X

    print(max(X, Y))
