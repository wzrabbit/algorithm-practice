while True:
    try:
        arr = list(map(int, input().split()))
        result = arr[:]

        for i in range(len(arr)):
            if i - 1 >= 0:
                result[i] *= arr[i - 1]
            if i + 1 < len(arr):
                result[i] *= arr[i + 1]
        
        print(*result)
    except EOFError:
        break
