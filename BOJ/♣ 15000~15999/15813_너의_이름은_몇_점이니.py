N = int(input())
S = input().replace(' ', '')
score = 0

for i in range(N):
    score += ord(S[i]) - 64

print(score)
