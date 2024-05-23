N = int(input())
original_arr = list(map(int, input().split()))
reversed_arr = original_arr[::-1]

def get_swap_count(arr):
    swap_count = 0
     
    for i in range(N - 1):
        for j in range(i + 1, N):
            if arr[i] > arr[j]:
                arr[i], arr[j] = arr[j], arr[i]
                swap_count += 1
                
    return swap_count

print(
    min(
        get_swap_count(original_arr),
        get_swap_count(reversed_arr) + 1
    )
)
