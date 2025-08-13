N = int(input())
answer = 0

for i in range(3, N + 1, 3):
    for j in range(3, N + 1, 3):
        if i + j + 3 <= N:
            answer += 1

print(answer)
