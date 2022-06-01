while True:
    try:
        game = input().split()[1]
        print(game[-1])
    except EOFError:
        break
