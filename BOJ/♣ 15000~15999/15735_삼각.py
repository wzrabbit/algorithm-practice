N = int(input())
answer = 0
cur = 0

for i in range(1, N + 1):
    cur += i
    answer += cur

    if (i + N) % 2 == 1 and i != N:
        answer += cur

print(answer)
