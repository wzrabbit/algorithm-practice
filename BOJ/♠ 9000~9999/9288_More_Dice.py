T = int(input())

for t in range(1, T + 1):
    N = int(input())
    
    print(f'Case {t}:')

    for i in range(1, N // 2 + 1):
        if 1 <= i <= 6 and i <= N - i <= 6:
            print(f'({i},{N - i})')
