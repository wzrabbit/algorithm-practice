N = int(input())
arr = list(input())

l = 0
r = N - 1
answer = 0

while l < r:
    if arr[l] != arr[r]:
        if arr[l] > arr[r]:
            arr[l] = arr[r]
        else:
            arr[r] = arr[l]

        answer += 1

    l += 1
    r -= 1

print(answer)
print("".join(arr))
