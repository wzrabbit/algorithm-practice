N, K = map(int, input().split())
S = input()

for i in range(K - 1):
    print(S[i], end = '')
    
for i in range(K - 1, N):
    if S[i].lower() == S[i]:
        print(S[i].upper(), end = '')
    else:
        print(S[i].lower(), end = '')
