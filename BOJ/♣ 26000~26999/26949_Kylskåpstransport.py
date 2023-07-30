price_a, limit_a, price_b,  limit_b, N = map(int, input().split())
best_a = -1
best_b = -1
best_price = 10 ** 10

for a in range(101):
    for b in range(101):
        cur_price = price_a * a + price_b * b
        cur_moves = limit_a * a + limit_b * b

        if cur_moves >= N and cur_price < best_price:
            best_a = a
            best_b = b
            best_price = cur_price

print(best_a, best_b, best_price)
