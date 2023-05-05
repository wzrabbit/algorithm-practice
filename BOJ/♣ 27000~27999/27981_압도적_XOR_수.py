def calculate_level(N, level):
    total = 2 ** level - 1
    start = 2 ** (level - 1)
    end = min(total - 1, N)
    mid = None
    end_range = end

    if N < start:
        return 0

    while start <= end:
        mid = (start + end) // 2
        if mid // (total - mid) >= K:
            end = mid - 1
        else:
            start = mid + 1

    total = end_range - start + 1

    if end_range + 1 <= N:
        total += 1

    return total


N, K = map(int, input().split())
K = 2 ** K - 1
total = 0

for i in range(1, 51):
    total += calculate_level(N, i)

print(total)
