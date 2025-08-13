N, D = map(int, input().split())
answer = 0

for i in range(1, N + 1):
    answer += str(i).count(str(D))

print(answer)
