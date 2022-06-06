n = int(input())
arr = list(map(float, input().split()))
flag = True
answer = 0

for i in range(len(arr)):
    if arr[i] % 1 != 0 and flag:
        answer += 1

    if arr[i] != 0:
        flag = False

    answer += int(arr[i])

print(answer)
