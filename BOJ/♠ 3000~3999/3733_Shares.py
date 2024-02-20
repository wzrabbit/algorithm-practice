while True:
    try:
        N, S = map(int, input().split())
        print(S // (N + 1))
    except EOFError:
        break
