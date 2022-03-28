import sys
t = []
for _ in range(3):
    t.append(tuple(map(int, sys.stdin.readline().split(' '))))

if (t[1][0] - t[0][0]) * (t[2][1] - t[0][1]) - (t[2][0] - t[0][0]) * (t[1][1] - t[0][1]) == 0:
    print('WHERE IS MY CHICKEN?')
else:
    print('WINNER WINNER CHICKEN DINNER!')
