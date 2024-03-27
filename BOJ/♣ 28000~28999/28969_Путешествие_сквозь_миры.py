A, B = map(int, input().split())
answer = 0

for i in range(1, 10):
    for j in range(1, 19):
        cur = int(str(i) * j)

        if A <= cur <= B:
            answer += 1

print(answer)
