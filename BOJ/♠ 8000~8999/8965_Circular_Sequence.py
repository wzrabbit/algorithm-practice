N = int(input())

for _ in range(N):
    S = input() * 2
    best = S[: len(S) // 2]

    for i in range(1, len(S) // 2):
        cur = S[i : len(S) // 2 + i]
        if cur < best:
            best = cur

    print(best)
