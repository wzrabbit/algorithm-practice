N = int(input())
arr = list(map(int, input().split()))
prev = arr[0]
answer = [arr[0]]

for i in range(1, N):
    if prev < arr[i]:
        prev = arr[i]
        answer.append(arr[i])

print(len(answer))
print(*answer)
