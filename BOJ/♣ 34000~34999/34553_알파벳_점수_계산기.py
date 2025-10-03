S = input()
score = 1
combo = 1

for i in range(1, len(S)):
    if S[i] > S[i - 1]:
        combo += 1
    else:
        combo = 1

    score += combo

print(score)
