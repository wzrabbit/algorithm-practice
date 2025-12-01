N = int(input())
answer = [input() for _ in range(N)]
choices = [input() for _ in range(N)]
score = 0

for i in range(N):
    if answer[i] == choices[i]:
        score += 1

print(score)
