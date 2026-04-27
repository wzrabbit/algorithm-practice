A, B, C = map(int, input().split())
answer = 0

for i in range(A, B + 1):
    answer += str(i).count(str(C))

print(answer)
