n = int(input())
for _ in range(n):
    x, y = list(map(int, input().split()))

    if x < y:
        print('NO BRAINS')
    else:
        print('MMM BRAINS')
