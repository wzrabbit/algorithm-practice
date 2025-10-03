A, B = map(int, input().split())
C, D = map(int, input().split())
answer = 0

while True:
    answer += 1
    A = (A + 1) % B
    C = (C + 1) % D

    if A == C == 0:
        print(answer)
        break
