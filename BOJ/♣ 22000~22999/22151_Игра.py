N = int(input())
for _ in range(N):
    limit, sr, sc, er, ec = map(int, input().split())
    dist = abs(sr - er) + abs(sc - ec)

    if dist <= limit:
        print('First 1')
    else:
        print('Infinity')
