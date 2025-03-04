X = int(input())
N = int(input())
answer = 0

while X < N:
    if X % 3 == 0:
        X += 1
    elif X % 3 == 1:
        X *= 2
    else:
        X *= 3

    answer += 1

print(answer)
