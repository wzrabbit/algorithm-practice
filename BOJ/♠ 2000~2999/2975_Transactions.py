while True:
    cur, query, money = input().split()
    cur = int(cur)
    money = int(money)

    if cur == 0 and query == 'W' and money == 0:
        break

    if query == 'W':
        if cur - money >= -200:
            print(cur - money)
        else:
            print('Not allowed')
    else:
        print(cur + money)
