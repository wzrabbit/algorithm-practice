N = int(input())
answer = 1

for i in range(1, N, 2):
    answer *= i

print(answer)
