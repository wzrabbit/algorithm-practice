import sys
input = sys.stdin.readline
print = sys.stdout.write

e, p, hp = map(int, input().split())
half = hp // 2
enemy = []
potion = []
result = []

for _ in range(e):
    enemy.append(int(input()))
for _ in range(p):
    potion.append(int(input()))

while hp > 0 and len(enemy) > 0:
    while len(potion) > 0 and hp <= half:
        result.append(len(potion))
        hp += potion[-1]
        potion.pop()

    while len(enemy) > 0 and (len(potion) == 0 or (len(potion) > 0 and hp > half)) and hp > 0:
        result.append(-len(enemy))
        hp -= enemy[-1]
        enemy.pop()

if hp <= 0:
    print('0')
else:
    while len(potion) > 0:
        result.append(len(potion))
        potion.pop()
    for i in result:
        print(str(i) + '\n')
