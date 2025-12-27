gold_bars = list(map(int, input().split()))

if max(gold_bars) == sum(gold_bars) // 2:
    print(0)
    exit(0)

for i in range(3):
    large = 0
    small = 10 ** 9

    for j in range(3):
        if j != i:
            large = max(large, gold_bars[j])
            small = min(small, gold_bars[j])

    if small + gold_bars[i] < large:
        continue

    half = sum(gold_bars) // 2

    print(i + 1)
    print(half - small, half - large)
    exit(0)

print(-1)
