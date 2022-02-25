import sys
input = sys.stdin.readline
length = int(input())
arr = list(map(int, input().split(' ')))
changed = 0

while True:
    zero = True
    even = True
    for i in range(length):
        if arr[i] % 2 == 1:
            zero = False
            even = False
            arr[i] -= 1
            changed += 1
        elif arr[i] > 0:
            zero = False

    if zero == True:
        break

    if even == True:
        for i in range(length):
            arr[i] = arr[i] // 2
        changed += 1

print(changed)