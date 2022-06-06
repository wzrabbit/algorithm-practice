import sys
print = sys.stdout.write

n = int(input())
frog = 1
print(f'{n ** 2 + n * 2}\n')

for i in range(1, n + 1):
    for j in range(1, i + 1):
        print(f'{frog} {j}\n')
    frog = 1 if frog == 2 else 2

for i in range(1, n + 1):
    print(f'{frog} {i}\n')
frog = 1 if frog == 2 else 2

for i in range(1, n + 1):
    for j in range(i, n + 1):
        print(f'{frog} {j}\n')
    frog = 1 if frog == 2 else 2
