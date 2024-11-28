r1, c1 = map(int, input().split())
r2, c2 = map(int, input().split())

if r1 == 0 or c1 == 0:
    if r1 == 0 and r2 == 0 and c2 < c1:
        print(3)
        exit()

    if c1 == 0 and c2 == 0 and r2 < r1:
        print(3)
        exit()

    print(1)
else:
    print(2)
