N = int(input())
up = list(map(int, input().split()))
down = list(map(int, input().split()))

answer = 2

for i in range(N):
    answer = min(answer, up[i] + down[i])

if answer == 1:
    for i in range(N - 1):
        if up[i] != up[i + 1] and down[i] != down[i + 1]:
            answer = 0
            break

print(answer)
