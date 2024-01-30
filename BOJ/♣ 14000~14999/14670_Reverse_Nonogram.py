while True:
    N = int(input())
    grid = []

    if N == 0:
        break

    for _ in range(N):
        grid.append(input())

    for r in range(N):
        combo = 0
        printed = False

        for c in range(N):
            if grid[r][c] == "X":
                combo += 1

            if grid[r][c] == "." or c == N - 1:
                if combo > 0:
                    print(combo, end=" ")
                    printed = True

                combo = 0

        if not printed:
            print(0, end=" ")

        print()

    for c in range(N):
        combo = 0
        printed = False

        for r in range(N):
            if grid[r][c] == "X":
                combo += 1

            if grid[r][c] == "." or r == N - 1:
                if combo > 0:
                    print(combo, end=" ")
                    printed = True

                combo = 0

        if not printed:
            print(0, end=" ")

        print()
