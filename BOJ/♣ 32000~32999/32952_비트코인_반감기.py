R, K, M = map(int, input().split())
half_count = M // K

for _ in range(half_count):
    R //= 2

    if R == 0:
        break

print(R)
