import sys
print = sys.stdout.write

N = int(input())

if N % 2 == 0:
    for i in range(N // 2):
        print(f'{N // 2 - i} { N // 2 + i + 1} ')
else:
    print(f'{N // 2 + 1} ')

    for i in range(N // 2):
        print(f'{N // 2 - i} { N // 2 + i + 2} ')
