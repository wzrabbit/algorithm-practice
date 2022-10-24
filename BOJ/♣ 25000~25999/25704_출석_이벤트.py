stamp = int(input())
money = int(input())
best = money

if stamp >= 5:
    best = min(best, money - 500)

if stamp >= 10:
    best = min(best, money // 10 * 9)

if stamp >= 15:
    best = min(best, money - 2000)

if stamp >= 20:
    best = min(best, money // 4 * 3)

if best < 0:
    best = 0

print(best)
