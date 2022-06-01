import sys
input = sys.stdin.readline
print = sys.stdout.write
no = 1

while True:
    n = int(input())
    if n == 0:
        break

    arr = list(map(int, input().split()))
    changed = 0
    success = False

    while changed <= 1000:
        same = True
        for i in range(1, n):
            if arr[i - 1] != arr[i]:
                same = False
                break

        if same:
            success = True
            break

        temp = abs(arr[0] - arr[-1])
        for i in range(n - 1):
            arr[i] = abs(arr[i] - arr[i + 1])
        arr[-1] = temp

        changed += 1

    if success:
        print(f'Case {no}: {changed} iterations\n')
    else:
        print(f'Case {no}: not attained\n')

    no += 1
