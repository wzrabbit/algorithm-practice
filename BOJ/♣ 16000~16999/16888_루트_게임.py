import sys
cases = int(sys.stdin.readline())
square = []
dp = [0]

for i in range(1, 1001):
    square.append(i ** 2)

for h in range(cases):
    game = int(sys.stdin.readline())
    if game >= len(dp):
        for i in range(len(dp), game + 1):
            for j in square:
                if i == j or (i - j > 0 and dp[i - j] == 'c'):
                    dp.append('k')
                    break
                elif i - j < 0:
                    dp.append('c')
                    break
    if dp[game] == 'k':
        print('koosaga')
    else:
        print('cubelover')
