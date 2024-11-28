N = int(input())
answer = 0

for _ in range(N):
    cur = int(input())

    if cur % 2 == 1:
        answer += 1

print(answer)
