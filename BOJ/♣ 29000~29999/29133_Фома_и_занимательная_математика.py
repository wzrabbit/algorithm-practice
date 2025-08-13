A, B, C, D = map(int, input().split())
answer = -1
answer_count = 0

for i in range(1, 4):
    if A ** i + B ** i + C ** i == D:
        answer = i
        answer_count += 1

if answer_count == 1:
    print(answer)
else:
    print(-1)
