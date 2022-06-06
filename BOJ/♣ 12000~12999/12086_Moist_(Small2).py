import sys
input = sys.stdin.readline
print = sys.stdout.write

t = int(input())
for no in range(1, t + 1):
    n = int(input())
    card = []
    cost = 0

    for __ in range(n):
        card.append(input().strip())

    for i in range(n - 1):
        if card[i] > card[i + 1]:
            cost += 1
            card[i], card[i + 1] = card[i + 1], card[i]

    print(f'Case #{no}: {cost}\n')
