N = int(input())
S = input()

l = 0
r = N - 1

while l < r:
    if S[l] != S[r] and S[l] != '?' and S[r] != '?':
        print(0)
        exit()
    
    l += 1
    r -= 1

answer = 0

l = 0
r = N - 1

while l < r:
    if S[l] == '?' and S[r] == '?':
        answer += 26
    elif S[l] == '?' or S[r] == '?':
        answer += 1

    l += 1
    r -= 1

print(answer)
