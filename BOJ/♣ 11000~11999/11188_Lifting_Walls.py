W, H, N, D = map(int, input().split())
crane_possible = []
pos = (
    {'x': W / 2, 'y': 0},
    {'x': -W / 2, 'y': 0},
    {'x': 0, 'y': H / 2},
    {'x': 0, 'y': -H / 2}
)
for _ in range(N):
    x, y = map(int, input().split())
    crane = []

    for i in range(4):
        dist = abs(x - pos[i]['x']) ** 2 + abs(y - pos[i]['y']) ** 2
        if dist <= D ** 2:
            crane.append(str(i))

    crane_possible.append(''.join(sorted(crane)))

if '0123' in crane_possible:
    print(1)
    exit(0)

for i in range(N - 1):
    for j in range(i + 1, N):
        merged = crane_possible[i] + crane_possible[j]
        if '0' in merged and '1' in merged and '2' in merged and '3' in merged:
            print(2)
            exit(0)

for i in range(N - 2):
    for j in range(i + 1, N - 1):
        for k in range(j + 1, N):
            merged = crane_possible[i] + crane_possible[j] + crane_possible[k]
            if '0' in merged and '1' in merged and '2' in merged and '3' in merged:
                print(3)
                exit(0)

for i in range(N - 3):
    for j in range(i + 1, N - 2):
        for k in range(j + 1, N - 1):
            for l in range(k + 1, N):
                merged = (crane_possible[i] + crane_possible[j] +
                          crane_possible[k] + crane_possible[l])
                if '0' in merged and '1' in merged and '2' in merged and '3' in merged:
                    print(4)
                    exit(0)

print('Impossible')
