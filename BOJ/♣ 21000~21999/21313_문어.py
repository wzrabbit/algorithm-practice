N = int(input())

if N % 2 == 0:
    print('1 2 ' * (N // 2))
else:
    print('1 2 ' * (N // 2) + '3')
