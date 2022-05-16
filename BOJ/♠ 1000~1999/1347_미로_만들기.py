import sys
input = sys.stdin.readline
print = sys.stdout.write

dr = [-1, 0, 1, 0]
dc = [0, 1, 0, -1]

n = int(input())
query = input().strip()
board = [['#' for j in range(101)] for i in range(101)]
pos = {'r': 50, 'c': 50, 'd': 2}
board[50][50] = '.'
u = {'r': 50, 'c': 50}
d = {'r': 50, 'c': 50}

for q in query:
    if q == 'L':
        pos['d'] = (pos['d'] - 1) % 4
    elif q == 'R':
        pos['d'] = (pos['d'] + 1) % 4
    else:
        pos['r'] = pos['r'] + dr[pos['d']]
        pos['c'] = pos['c'] + dc[pos['d']]
        board[pos['r']][pos['c']] = '.'

        if pos['r'] < u['r']:
            u['r'] = pos['r']
        if pos['c'] < u['c']:
            u['c'] = pos['c']
        if pos['r'] > d['r']:
            d['r'] = pos['r']
        if pos['c'] > d['c']:
            d['c'] = pos['c']

for r in range(u['r'], d['r'] + 1):
    for c in range(u['c'], d['c'] + 1):
        print(board[r][c])
    print('\n')
