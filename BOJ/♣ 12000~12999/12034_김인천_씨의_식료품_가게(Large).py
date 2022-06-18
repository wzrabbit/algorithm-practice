import sys
input = sys.stdin.readline
print = sys.stdout.write

t = int(input())

for no in range(1, t + 1):
    n = int(input())
    arr = list(map(int, input().split()))

    print(f'Case #{no}: ')

    for i in range(n // 2):
        found = arr[0]
        print(str(found) + ' ')
        arr.pop(0)
        arr.remove(found * 4 // 3)

    print('\n')
