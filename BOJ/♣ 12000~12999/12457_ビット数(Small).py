T = int(input())

for t in range(1, T + 1):
    N = int(input())
    best = 0

    for i in range(N):
        A = bin(i).count("1")
        B = bin(N - i).count("1")
        best = max(best, A + B)

    print(f"Case #{t}: {best}")
