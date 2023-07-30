N = int(input())
D, T = map(int, input().split())
dough = int(input())
toppings = []

for _ in range(N):
    toppings.append(int(input()))

toppings.sort(reverse=True)

weight = D
kcal = dough
best_kcal = kcal // weight

for i in range(N):
    weight += T
    kcal += toppings[i]
    best_kcal = max(best_kcal, kcal // weight)

print(best_kcal)
