N, M = map(int, input().split())
answer = 1

for i in range(1, N + 1):
    answer *= i
    answer %= M

print(answer)
