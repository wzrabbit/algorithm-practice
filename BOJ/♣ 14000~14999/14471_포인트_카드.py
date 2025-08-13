N, M = map(int, input().split())
cards = []
cost = 0

for _ in range(M):
    cards.append(list(map(int, input().split())))

cards.sort(reverse=True)

for i in range(M - 1):
    cost += max(0, cards[i][1] - N)

print(cost)
