menu, money = map(int, input().split())
upgrade_chance = (money - menu * 1000) // 4000
taste = 0
gap = []

for _ in range(menu):
    menu_5000, menu_1000 = map(int, input().split())
    current_gap = menu_5000 - menu_1000
    taste += menu_1000
    
    if current_gap > 0:
        gap.append(menu_5000 - menu_1000)
    
gap.sort(reverse=True)

for i in range(len(gap)):
    if upgrade_chance <= 0:
        break
    
    taste += gap[i]
    upgrade_chance -= 1
    
print(taste)