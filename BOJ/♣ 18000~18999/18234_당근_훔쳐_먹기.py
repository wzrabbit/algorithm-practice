import sys
amount, day = list(map(int, sys.stdin.readline().split()))
carrot = []
total = 0

for _ in range(amount):
    carrot.append(list(map(int, sys.stdin.readline().split())))
carrot.sort(key=lambda x: x[1])

gap = 0
if amount < day:
    gap = day - amount

for i in range(min(amount, day)):
    total += carrot[i][0] + (gap + i) * carrot[i][1]

print(total)
