N = int(input())
arr = list(map(int, input().split()))
chances = int(input())

for i in range(N - 1):
    best_value = arr[i]
    best_index = i

    for j in range(i + 1, min(i + 1 + chances, N)):
        if best_value < arr[j]:
            best_value = arr[j]
            best_index = j

    for j in reversed(range(i, best_index)):
        arr[j], arr[j + 1] = arr[j + 1], arr[j]

    chances -= best_index - i

print(*arr)
