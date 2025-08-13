N = int(input())
arr = [int(input()) for _ in range(N)]

if arr[0] == min(arr):
    print('ez')
elif arr[0] == max(arr):
    print('hard')
else:
    print('?')
