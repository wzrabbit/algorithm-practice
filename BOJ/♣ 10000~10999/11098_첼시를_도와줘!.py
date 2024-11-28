T = int(input())

for _ in range(T):
    N = int(input())
    best_player = ""
    best_price = 0

    for __ in range(N):
        price, player = input().split()
        price = int(price)

        if price > best_price:
            best_price = price
            best_player = player

    print(best_player)
