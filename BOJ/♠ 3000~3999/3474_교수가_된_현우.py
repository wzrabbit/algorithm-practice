import sys
input = sys.stdin.readline
print = sys.stdout.write

t = int(input())
for _ in range(t):
    n = int(input())
    div = 5
    total = 0

    while n >= div:
        total += n // div
        div *= 5

    print(str(total) + '\n')
