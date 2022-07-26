def get_swap_count(part):
    count = 0

    for i in range(len(part)):
        for j in range(len(part) - i - 1):
            if part[j] > part[j + 1]:
                part[j], part[j + 1] = part[j + 1], part[j]
                count += 1

    return count, part


N = int(input())
arr = list(map(int, input().split()))
sorted_arr = sorted(arr)
K = int(input())
count = 0

for i in range(K):
    part = []
    for j in range(i, N, K):
        part.append(arr[j])

    plus, part = get_swap_count(part)
    count += plus
    k = 0
    for j in range(i, N, K):
        arr[j] = part[k]
        k += 1

if arr == sorted_arr:
    print(count)
else:
    print(-1)
