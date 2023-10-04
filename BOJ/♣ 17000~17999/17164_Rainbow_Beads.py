N = int(input())
beads = input()
max_combo = 1
combo = 1

for i in range(1, N):
    if beads[i - 1] + beads[i] in ("RB", "BR"):
        combo += 1
    else:
        combo = 1

    max_combo = max(max_combo, combo)

print(max_combo)
