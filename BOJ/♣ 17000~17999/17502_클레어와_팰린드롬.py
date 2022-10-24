N = int(input())
S = list(input())
l = 0
r = N - 1

while l <= r:
    if S[l] == '?' and S[r] == '?':
        S[l] = 'a'
        S[r] = 'a'
    elif S[l] == '?' and S[r] != '?':
        S[l] = S[r]
    elif S[l] != '?' and S[r] != 'a':
        S[r] = S[l]

    l += 1
    r -= 1

print(''.join(S))
