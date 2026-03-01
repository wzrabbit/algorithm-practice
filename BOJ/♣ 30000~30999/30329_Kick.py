S = input()
answer = 0

for i in range(len(S) - 3):
    if S[i:i+4] == 'kick':
        answer += 1

print(answer)
