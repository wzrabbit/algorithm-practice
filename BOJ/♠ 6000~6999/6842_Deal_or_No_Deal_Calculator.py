values = [None, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000]

N = int(input())
revealed = [int(input()) for _ in range(N)]
offer_price = int(input())

average = 0

for i in range(1, 11):
    if i not in revealed:
        average += values[i]

average //= (10 - N)

if average < offer_price:
    print('deal')
else:
    print('no deal')
