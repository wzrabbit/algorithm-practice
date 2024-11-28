T = int(input())

for i in range(1, T + 1):
    A, B, C = sorted(list(map(int, input().split())))
    kind_count = len(set([A, B, C]))

    if A + B <= C:
        print(f'Case #{i}: invalid!')
        continue

    if kind_count == 1:
        print(f'Case #{i}: equilateral')
        continue

    if kind_count == 2:
        print(f'Case #{i}: isosceles')
        continue

    print(f'Case #{i}: scalene')
