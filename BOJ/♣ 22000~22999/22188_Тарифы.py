N, C = map(int, input().split())
best = {'index': -1, 'price': 99999999999}

choice = []
for _ in range(N):
    choice.append(list(map(int, input().split())))
history = list(map(int, input().split()))

for i in range(N):
    register, interval, extra = choice[i]
    calc = register * 100

    for j in range(C):
        if history[j] >= interval:
            mul = history[j] // interval
            if history[j] % interval > 0:
                mul += 1

            calc += extra * mul

    if calc < best['price']:
        best['index'] = i + 1
        best['price'] = calc

print(best['index'])
