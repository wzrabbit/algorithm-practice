import sys
from collections import deque

row, col = map(int, input().split())
board = []
for r in range(row):
    board.append(list(map(int, input().split())))
a, d, b, e = map(int, input().split())

dr = (-1, 0, 1, 0)
dc = (0, 1, 0, -1)

ari = {'r': 0, 'c': 0, 'pr': 0, 'pc': 0, 'hp': a, 'atk': d, 'pos': 0}
boss = {'r': 0, 'c': 0, 'hp': b, 'atk': e, 'pos': 0}

for r in range(row):
    for c in range(col):
        if board[r][c] == 2:
            ari['r'] = r
            ari['c'] = c
        elif board[r][c] == 3:
            boss['r'] = r
            boss['c'] = c

for i in range(4):
    r = boss['r'] + dr[i]
    c = boss['c'] + dc[i]
    if 0 <= r < row and 0 <= c < col and board[r][c] == 2:
        boss['pos'] = i
    ari['pos'] = boss['pos']


def ari_atk():
    boss['hp'] -= ari['atk']
    if boss['hp'] <= 0:
        return True
    else:
        return False


def ari_move():
    ari['pr'] = ari['r']
    ari['pc'] = ari['c']
    board[ari['pr']][ari['pc']] = 0
    for _ in range(4):
        r = ari['r'] + dr[ari['pos']]
        c = ari['c'] + dc[ari['pos']]

        if 0 <= r < row and 0 <= c < col and board[r][c] == 0:
            ari['r'] = r
            ari['c'] = c
            board[ari['r']][ari['c']] = 2
            return False
        else:
            ari['pos'] = (ari['pos'] + 1) % 4
            ari['hp'] -= 1
            if ari['hp'] <= 0:
                return True
    board[ari['r']][ari['c']] = 2
    return False


def search_stone():
    t_pos = boss['pos']
    r = boss['r']
    c = boss['c']
    speed = 2
    checked = 1
    while checked < row * col:
        for i in range(speed // 2):
            r = r + dr[t_pos]
            c = c + dc[t_pos]

            if checked >= row * col:
                break

            if 0 <= r < row and 0 <= c < col:
                checked += 1
                if board[r][c] == 1:
                    return [r, c]
        speed += 1
        t_pos = (t_pos + 1) % 4
    return [-1, -1]


def attack_ari(ro, co):
    que = deque()
    visited = [[-1 for c in range(col)] for r in range(row)]
    que.append((ro, co))
    visited[ro][co] = 0

    while len(que):
        r_, c_ = que.popleft()
        if visited[r_][c_] >= boss['atk']:
            return False

        if board[r_][c_] == 2:
            ari['hp'] -= boss['atk'] - visited[r_][c_]
            if ari['hp'] <= 0:
                return True
            else:
                return False

        for i in range(4):
            r = r_ + dr[i]
            c = c_ + dc[i]

            if 0 <= r < row and 0 <= c < col and visited[r][c] == -1 and (board[r][c] == 0 or board[r][c] == 2):
                visited[r][c] = visited[r_][c_] + 1
                que.append((r, c))
    return False


def boss_move():
    if ari['pr'] == ari['r'] and ari['pc'] == ari['c']:
        return
    board[boss['r']][boss['c']] = 0
    boss['r'] = ari['pr']
    boss['c'] = ari['pc']
    boss['pos'] = ari['pos']
    board[boss['r']][boss['c']] = 3


while True:
    is_victory = ari_atk()
    if is_victory:
        print('VICTORY!')
        break

    is_died = ari_move()
    if is_died:
        print('CAVELIFE...')
        break

    minion_r, minion_c = search_stone()
    if minion_r != -1:
        is_died = attack_ari(minion_r, minion_c)
        if is_died:
            print('CAVELIFE...')
            break

    boss_move()
