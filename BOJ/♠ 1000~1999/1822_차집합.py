A, B = map(int, input().split())
A_arr = list(map(int, input().split()))
B_arr = list(map(int, input().split()))
result = []
A_arr.sort()
B_arr.sort()


def is_found(X):
    start = 0
    end = B - 1
    mid = ''

    while start <= end:
        mid = (start + end) // 2

        if X < B_arr[mid]:
            end = mid - 1
        elif X > B_arr[mid]:
            start = mid + 1
        else:
            return True

    return False


for i in range(A):
    if not is_found(A_arr[i]):
        result.append(A_arr[i])

print(len(result))
for i in range(len(result)):
    print(result[i], end=' ')
