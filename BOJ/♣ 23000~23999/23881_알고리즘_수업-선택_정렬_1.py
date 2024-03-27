N, K = map(int, input().split())
arr = list(map(int, input().split()))
swap_count = 0

for i in reversed(range(1, N)):
    max_number = 0
    max_index = 0

    for j in range(i):
        if arr[j] > max_number:
            max_number = arr[j]
            max_index = j

    if max_number > arr[i]:
        arr[max_index], arr[i] = arr[i], arr[max_index]
        swap_count += 1

        if swap_count == K:
            print(arr[max_index], arr[i])
            exit(0)

print(-1)
