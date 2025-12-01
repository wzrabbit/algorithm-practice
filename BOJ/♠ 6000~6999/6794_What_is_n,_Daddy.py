N = int(input())
answer = 0

for i in range(0, 6):
    for j in range(i, 6):
        if i + j == N:
            answer += 1

print(answer)
