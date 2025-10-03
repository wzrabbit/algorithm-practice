T = int(input())

for _ in range(T):
    A, B = map(int, input().split())

    if A <= 2 and B <= 1 or A <= 1 and B <= 2:
        print('Yes')
    else:
        print('No')
