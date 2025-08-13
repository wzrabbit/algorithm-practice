N, M, __, L = map(int, input().split())

if (N + M - 2) % 2 != L % 2 or (N + M - 2) > L:
    print(-1)
    exit()

print("D" * (N - 1), end="")
print("R" * (M - 1), end="")
print("LR" * ((L - N - M + 2) // 2))
