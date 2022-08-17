burger = 10000
drink = 10000

for _ in range(3):
    burger = min(int(input()), burger)

for _ in range(2):
    drink = min(int(input()), drink)

print(burger + drink - 50)
