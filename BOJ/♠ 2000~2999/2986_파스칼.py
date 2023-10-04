N = int(input())
i = 2
answer = N - 1

while i * i <= N:
    if N % i == 0:
        answer = N - N // i
        break

    i += 1

print(answer)
