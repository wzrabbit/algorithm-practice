R, C = map(int, input().split())
town = []
dr = (-1, 1, 0, 0)
dc = (0, 0, -1, 1)
is_blocked = False

for r in range(R):
    town.append(list(input()))

for r in range(R):
    for c in range(C):
        if town[r][c] == 'X':
            continue
        
        way = 0
        for i in range(4):
            next_r = r + dr[i]
            next_c = c + dc[i]
            if 0 <= next_r < R and 0 <= next_c < C and town[next_r][next_c] == '.':
                way += 1
        
        if way == 1:
            is_blocked = True
            
if is_blocked:
    print(1)
else:
    print(0)