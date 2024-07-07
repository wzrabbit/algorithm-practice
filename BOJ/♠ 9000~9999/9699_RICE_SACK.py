T = int(input())

for t in range(1, T + 1):
    arr = list(map(int, input().split()))

    print(f'Case #{t}: {max(arr)}')
