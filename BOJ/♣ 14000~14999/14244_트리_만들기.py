vertex, leaf = map(int, input().split())

for i in range(1, leaf + 1):
    print(f'0 {i}')

for i in range(leaf + 1, vertex):
    print(f'{i - 1} {i}')
