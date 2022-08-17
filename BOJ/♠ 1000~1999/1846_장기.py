import sys
print = sys.stdout.write

N = int(input())
if N == 3:
    print('-1')
    sys.exit()

x = 2
i = 1
while i <= N:
    if i == N // 2:
        print('1\n')
    elif i == N // 2 + 1:
        print(f'{N}\n')
    else:
        print(f'{x}\n')
        x += 1
    i += 1
