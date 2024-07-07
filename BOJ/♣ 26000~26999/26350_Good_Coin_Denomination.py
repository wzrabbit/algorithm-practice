T = int(input())

for t in range(T):
    N, *prices = list(map(int, input().split()))
    is_good = True

    for i in range(N - 1):
        if prices[i] * 2 > prices[i + 1]:
            is_good = False
            break

    print(f'Denominations: ', end = '')
    print(*prices, sep = ' ', end = '\n')
    print('Good coin denominations!' if is_good else 'Bad coin denominations!')

