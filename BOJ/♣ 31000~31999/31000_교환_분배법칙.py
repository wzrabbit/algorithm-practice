N = int(input())
answer = (N * 2 + 1) ** 2

for a in range(-N, N + 1):
    for b in range(-N, N + 1):
        if a == 0:
            continue

        c = 1 - a - b

        if -N <= c <= N:
            answer += 1

print(answer)
