while True:
    try:
        num = int(input())
        mod = 1 % num
        count = 1

        while mod != 0:
            mod = (mod * 10 + 1) % num
            count += 1
        print(count)
    except EOFError:
        break
