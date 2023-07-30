import math

T = int(input())

for t in range(1, T + 1):
    N, pooh = input().split()
    N = int(N)
    pooh = float(pooh)
    total = 0

    for _ in range(N):
        r = float(input())
        total += 4 / 3 * math.pi * (r**3) / 1000

    print(f"Data Set {t}:")

    if total >= pooh:
        print("Yes\n")
    else:
        print("No\n")
