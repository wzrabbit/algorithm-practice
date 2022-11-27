while True:
    N = input()
    width = 0

    if N == '0':
        break

    for cur in N:
        if cur == '0':
            width += 4
        elif cur == '1':
            width += 2
        else:
            width += 3

    width += len(N) + 1
    print(width)
