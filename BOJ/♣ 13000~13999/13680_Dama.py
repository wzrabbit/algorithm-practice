while True:
    r1, c1, r2, c2 = map(int, input().split())

    if r1 == r2 == c1 == c2 == 0:
        break

    if r1 == r2 and c1 == c2:
        print(0)
        continue

    if r1 == r2 or c1 == c2 or abs(r1 - r2) == abs(c1 - c2):
        print(1)
        continue

    print(2)
