A_cool, A_dmg = map(int, input().split())
B_cool, B_dmg = map(int, input().split())
C_cool, C_dmg = map(int, input().split())
hp = int(input())
damage_arr = [0] * 1000001

for i in range(0, 1000001, A_cool):
    damage_arr[i] += A_dmg

for i in range(0, 1000001, B_cool):
    damage_arr[i] += B_dmg

for i in range(0, 1000001, C_cool):
    damage_arr[i] += C_dmg

for i in range(1000001):
    hp -= damage_arr[i]
    if hp <= 0:
        print(i)
        break
