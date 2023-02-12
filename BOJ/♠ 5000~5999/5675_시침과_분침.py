while True:
    try:
        angle = int(input())
        if angle % 6 == 0:
            print('Y')
        else:
            print('N')
    except EOFError:
        break
