T = int(input())

for _ in range(T):
    limit = int(input())
    pigs = list(map(int, input().split()))
    day = 1

    while True:
        if sum(pigs) > limit:
            print(day)
            break

        new_pigs = pigs[:]

        for i in range(6):
            new_pigs[i] += pigs[(i + 1) % 6] + pigs[(i + 3) % 6] + pigs[(i + 5) % 6]

        pigs = new_pigs[:]

        day += 1
