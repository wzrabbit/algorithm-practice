N = int(input())
arr = list(map(int, input().split()))
anger = 0
total_anger = 0

for i in range(N):
    if arr[i] == 0:
        anger -= 1
    else:
        anger += 1

    total_anger += anger

print(total_anger)
