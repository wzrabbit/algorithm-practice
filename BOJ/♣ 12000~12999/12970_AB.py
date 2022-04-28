import sys
input = sys.stdin.readline
print = sys.stdout.write

n, k = map(int, input().split())
success = False

for i in range(1, n + 1):
    space = [0] * i
    left = k

    for j in range(n - i + 1):
        if left > i - 1:
            space[i - 1] += 1
            left -= (i - 1)
        else:
            space[left] += 1
            left = 0

    if left > 0:
        continue
    else:
        success = True
        for i in reversed(range(1, i)):
            print('A' * space[i] + 'B')
        print('A' * space[0])
        break

if not success:
    print('-1')
