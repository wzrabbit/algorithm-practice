N = int(input())
arr = [0, 1, 12, 123, 1234, 12345, 123456, 1234567, 12345678, 123456789]

if N in arr:
    print(arr.index(N))
else:
    print(-1)
