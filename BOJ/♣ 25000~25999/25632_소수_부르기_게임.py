A, B = map(int, input().split())
C, D = map(int, input().split())
is_prime = [True] * 1001
is_prime[0] = False
is_prime[1] = False

for i in range(2, 33):
    if not is_prime[i]:
        continue
    for j in range(i * 2, 1001, i):
        is_prime[j] = False

player_A = 0
player_B = 0
player_both = 0

for i in range(2, 1001):
    if is_prime[i]:
        if A <= i <= B:
            player_A += 1
        if C <= i <= D:
            player_B += 1
        if A <= i <= B and C <= i <= D:
            player_both += 1

if player_both % 2 == 1:
    player_A += 1

if player_A > player_B:
    print('yt')
else:
    print('yj')
