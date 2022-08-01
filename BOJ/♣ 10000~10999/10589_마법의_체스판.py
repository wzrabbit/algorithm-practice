R, C = map(int, input().split())

print(R // 2 + C // 2)

for i in range(2, R + 1, 2):
    print(f'{i} 1 {i} {C}')

for i in range(2, C + 1, 2):
    print(f'1 {i} {R} {i}')
