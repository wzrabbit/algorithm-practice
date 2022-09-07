N = int(input())
coin = list(map(int, input().split()))

if sum(coin) - max(coin) < max(coin) or sum(coin) % 2 == 1:
    print('no')
    exit()


for i in range(N):
    coin[i] = [coin[i], i + 1]

print('yes')
while True:
    coin.sort(reverse=True)
    while len(coin) > 0 and coin[-1][0] == 0:
        coin.pop()

    if len(coin) == 0:
        break

    print(coin[0][1], coin[-1][1])
    coin[0][0] -= 1
    coin[-1][0] -= 1
