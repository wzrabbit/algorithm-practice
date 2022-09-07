N = int(input())
room = []
for _ in range(N):
    room.append(list(input()))
row_cnt = 0
col_cnt = 0

for r in range(N):
    combo = 0
    for c in range(N):
        if room[r][c] == '.':
            combo += 1
        else:
            combo = 0

        if combo == 2:
            col_cnt += 1

for c in range(N):
    combo = 0
    for r in range(N):
        if room[r][c] == '.':
            combo += 1
        else:
            combo = 0

        if combo == 2:
            row_cnt += 1

print(col_cnt, row_cnt)
