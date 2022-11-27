def change_to_max(num):
    return int('9' + str(num)[1:])


def change_to_min(num):
    num = str(num)
    digit = '0' if len(num) == 1 else '1'
    return int(digit + str(num)[1:])


def solve():
    for i in range(N):
        if i != 0 and arr[i - 1] > change_to_min(arr[i]):
            arr[i] = change_to_min(arr[i])
            return True
        if i != N - 1 and change_to_max(arr[i]) > arr[i + 1]:
            arr[i] = change_to_max(arr[i])
            return True


N = int(input())
arr = list(map(int, input().split()))

if solve():
    for i in range(N):
        print(str(arr[i]), end=' ')
else:
    print('impossible')
