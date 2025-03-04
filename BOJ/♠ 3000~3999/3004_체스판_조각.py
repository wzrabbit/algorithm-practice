N = int(input())
answer = 0

for i in range(N + 2):
    answer = max(answer, i * (N + 2 - i))

print(answer)
