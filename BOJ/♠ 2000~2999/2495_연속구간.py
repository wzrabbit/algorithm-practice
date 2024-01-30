for _ in range(3):
    S = input()
    max_combo = 1
    combo = 1

    for i in range(1, 8):
        if S[i] == S[i - 1]:
            combo += 1
        else:
            combo = 1

        max_combo = max(max_combo, combo)

    print(max_combo)
