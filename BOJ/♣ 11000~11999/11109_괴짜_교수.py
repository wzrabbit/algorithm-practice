T = int(input())

for _ in range(T):
    D, N, S, P = map(int, input().split())

    if D + N * P > N * S:
        print("do not parallelize")
    elif D + N * P < N * S:
        print("parallelize")
    else:
        print("does not matter")
