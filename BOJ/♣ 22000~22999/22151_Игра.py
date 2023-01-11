N = int(input())
for _ in range(N):
    limit, start_r, start_c, end_r, end_c = map(int, input().split())
    dist = abs(start_r - end_r) + abs(start_c - end_c)

    if dist <= limit:
        print('First 1')
    else:
        print('Infinity')
