N = int(input())
goal = list(map(int, input().split()))
result = list(map(int, input().split()))
answer = 0

for i in range(N):
    if goal[i] <= result[i]:
        answer += 1

print(answer)
