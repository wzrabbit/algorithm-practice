N = int(input())
arr = list(map(int, input().split()))
pos = arr.index(-1)

print(min(arr[:pos]) + min(arr[pos + 1 :]))
