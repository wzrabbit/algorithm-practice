import sys

input = sys.stdin.readline
print = sys.stdout.write

N = int(input())
arr = list(map(int, input().split()))

Q = int(input())
for _ in range(Q):
    command = list(map(int, input().split()))

    if command[0] == 1:
        l, r, k = command[1:]
        l -= 1
        r -= 1
        count = 0

        for i in range(l, r + 1):
            if arr[i] == k:
                count += 1

        print(f"{count}\n")
    else:
        l, r = command[1:]
        l -= 1
        r -= 1

        for i in range(l, r + 1):
            arr[i] = 0
