n = int(input())
dasom = int(input())
enemy = [-1]
for i in range(n - 1):
    enemy.append(int(input()))

count = 0
while True:
    max_ = max(enemy)
    if dasom > max_:
        print(count)
        break
    else:
        enemy[enemy.index(max_)] -= 1
        dasom += 1
        count += 1