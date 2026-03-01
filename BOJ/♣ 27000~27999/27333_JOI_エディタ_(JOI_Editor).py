N = int(input())
S = list(input())

for i in range(1, N):
    if S[i] == S[i - 1]:
        S[i - 1] = S[i - 1].upper()
        S[i] = S[i].upper()

print(''.join(S))
