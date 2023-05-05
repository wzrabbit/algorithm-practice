N = int(input())
arr = list(map(int, input().split()))
success = False
operations = 0

while not success:
    success = True

    for i in range(1, N - 1):
        if arr[i - 1] + arr[i + 1] < arr[i] * 2:
            decreased = (arr[i] * 2 - arr[i - 1] - arr[i + 1] + 1) // 2
            arr[i] -= decreased
            operations += decreased
            success = False

print(operations)
