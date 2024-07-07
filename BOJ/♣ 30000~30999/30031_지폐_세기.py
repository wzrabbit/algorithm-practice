N = int(input())
price = 0

for _ in range(N):
    width = int(input().split()[0])

    if width == 136:
        price += 1000
    elif width == 142:
        price += 5000
    elif width == 148:
        price += 10000
    else:
        price += 50000

print(price)
