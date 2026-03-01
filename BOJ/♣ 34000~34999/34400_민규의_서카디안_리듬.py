T = int(input())

for _ in range(T):
    N = int(input())

    if N % 25 < 17:
        print('ONLINE')
    else:
        print('OFFLINE')
