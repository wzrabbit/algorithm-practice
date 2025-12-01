P, M, C = map(int, input().split())
X = int(input())
answer = 10 ** 18

for p in range(1, P + 1):
    for m in range(1, M + 1):
        for c in range(1, C + 1):
            answer = min(answer, abs((p + m) * (m + c) - X))

print(answer)
