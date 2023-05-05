wr, wc = map(int, input().split())
br, bc = map(int, input().split())

if (abs(br - wr) + abs(bc - wc)) % 2 == 0:
    print('black')
else:
    print('white')
