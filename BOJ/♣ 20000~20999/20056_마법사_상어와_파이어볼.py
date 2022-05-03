import sys
from collections import deque
input = sys.stdin.readline

num, fire, command = map(int, input().split())
board = [[deque() for c in range(num)] for r in range(num)]
dr = (-1, -1, 0, 1, 1, 1, 0, -1)
dc = (0, 1, 1, 1, 0, -1, -1, -1)
turn = 1

for i in range(fire):
    r, c, m, s, d = map(int, input().split())
    r -= 1
    c -= 1

    board[r][c].append({'mass': m, 'direction': d, 'speed': s, 'no': 1})


for _ in range(command):

    # 1. 이동
    for r in range(num):
        for c in range(num):
            while len(board[r][c]) > 0 and board[r][c][0]['no'] == turn:
                current = board[r][c].popleft()
                current['no'] = turn + 1
                next_r = (r + dr[current['direction']]
                          * current['speed']) % num
                next_c = (c + dc[current['direction']]
                          * current['speed']) % num
                board[next_r][next_c].append(current)
    turn += 1

    # 2. 결합 및 분해
    for r in range(num):
        for c in range(num):
            if len(board[r][c]) <= 1:
                for i in range(len(board[r][c])):
                    board[r][c][i]['no'] = turn + 1
                continue

            cnt = 0
            total_mass = 0
            total_speed = 0
            dir = []
            new_dir = []
            odd = 0
            even = 0

            while len(board[r][c]) > 0 and board[r][c][0]['no'] == turn:
                current = board[r][c].popleft()
                cnt += 1
                total_mass += current['mass']
                total_speed += current['speed']
                dir.append(current['direction'])

            for i in dir:
                if i % 2 == 0:
                    even += 1
                else:
                    odd += 1
            if even == 0 and odd > 0 or even > 0 and odd == 0:
                new_dir = [0, 2, 4, 6]
            else:
                new_dir = [1, 3, 5, 7]

            if total_mass >= 5:
                for i in range(4):
                    board[r][c].append(
                        {
                            'mass': total_mass // 5,
                            'direction': new_dir[i],
                            'speed': total_speed // len(dir),
                            'no': turn + 1
                        }
                    )
    turn += 1

answer = 0
for r in range(num):
    for c in range(num):
        while len(board[r][c]) > 0:
            current = board[r][c].popleft()
            answer += current['mass']

print(answer)
