N, T = map(int, input().split())
chance = True
scores = list(map(int, input().split()))
scores.sort(reverse=True)
answer = 0

for i in range(min(N, T)):
    if scores[i] > 0:
        answer += scores[i]
        scores[-(i+1)] = 0
        
print(answer)
