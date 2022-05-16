n = int(input())
arr = list(map(int, input().split()))
arr.sort()
left = arr[0]
right = arr[-1]
total = abs(arr[0] - arr[-1])
turn = 3

while turn <= n:
    if turn % 2 == 0:
        current = arr[-(turn // 2)]
    else:
        current = arr[turn // 2]

    if abs(left - current) > abs(right - current):
        total += abs(left - current)
        left = current
    else:
        total += abs(right - current)
        right = current
    turn += 1

print(total)
