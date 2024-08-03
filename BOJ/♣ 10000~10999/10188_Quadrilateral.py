T = int(input())

for _ in range(T):
    C, R = map(int, input().split())
    
    for _ in range(R):
        print('X' * C)

    print()
