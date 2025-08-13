N = int(input())
A = int(input())
B = int(input())

answer = 0

for i in range(1, N + 1):
    if i % A == 0 and i % B != 0:
        answer += 1

    if i % A != 0 and i % B == 0:
        answer += 1

print(answer)
