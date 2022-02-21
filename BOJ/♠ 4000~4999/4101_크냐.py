while True:
    a, b = list(map(int, input().split()))
    if a == 0:
        break
    if a > b:
        print('Yes')
    else:
        print('No')