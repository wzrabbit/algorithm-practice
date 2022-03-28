import sys
cases, alpha, beta = list(map(int, sys.stdin.readline().split(' ')))
cases = 8 - cases

for _ in range(cases):
    a, b = list(map(int, sys.stdin.readline().split(' ')))
    chance = 6
    alpha += min(a, 6) * 3
    beta += min(a, 6) * 3
    chance -= min(a, 6)
    beta += min(b, chance) * 3

if alpha >= 66 and beta >= 130:
    print('Nice')
else:
    print('Nae ga wae')
