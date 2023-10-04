N, remain_time = map(int, input().split())
tasks = list(map(int, input().split()))
answer = 0

for i in range(N):
    if tasks[i] > remain_time:
        break

    remain_time -= tasks[i]
    answer += 1

print(answer)
