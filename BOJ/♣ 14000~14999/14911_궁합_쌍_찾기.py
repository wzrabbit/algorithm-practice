arr = list(map(int, input().split()))
goal = int(input())
answer = []

for i in range(len(arr) - 1):
    for j in range(i + 1, len(arr)):
        if arr[i] + arr[j] == goal:
            answer.append((arr[i], arr[j]))

answer = list(set(answer))
answer.sort()

for a, b in answer:
    print(a, b)

print(len(answer))
