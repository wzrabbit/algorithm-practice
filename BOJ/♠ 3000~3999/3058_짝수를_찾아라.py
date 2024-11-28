T = int(input())

for _ in range(T):
    arr = list(map(int, input().split()))
    even_sum = 0
    even_min = 123

    for i in range(7):
        if arr[i] % 2 == 0:
            even_sum += arr[i]
            even_min = min(even_min, arr[i])

    print(even_sum, even_min)
