while True:
    a, b, c = sorted(list(map(int, input().split())))

    if a == 0:
        break

    if a + b <= c:
        print("Invalid")
        continue

    if a == b == c:
        print("Equilateral")
        continue

    if a == b or b == c:
        print("Isosceles")
        continue

    print("Scalene")
