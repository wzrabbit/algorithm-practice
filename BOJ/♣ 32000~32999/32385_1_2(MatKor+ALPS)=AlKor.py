import sys
print = sys.stdout.write

N = int(input())

if N % 2 == 0:
    print('-1 1 ')
else:
    print('-1 -2 3 ')

for i in range((N - 2) // 2 * 2):
    if i % 2 == 0:
        print(f'{i // 2 + 4} ')
    else:
        print(f'-{i // 2 + 4} ')

print('0')
