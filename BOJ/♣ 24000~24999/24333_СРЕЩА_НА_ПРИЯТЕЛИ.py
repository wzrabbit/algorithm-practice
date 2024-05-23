time = [0] * 50001
A, B, C, D, K = map(int, input().split())

for i in range(A, B + 1):
    time[i] += 1

for i in range(C, D + 1):
    time[i] += 1

time[K] -= 1

answer = 0

for i in range(1, 50001):
    if time[i] == 2:
        answer += 1

print(answer)
