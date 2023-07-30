odds = []

for _ in range(7):
    cur = int(input())

    if cur % 2 == 1:
        odds.append(cur)

if len(odds) == 0:
    print(-1)
else:
    print(sum(odds))
    print(min(odds))
