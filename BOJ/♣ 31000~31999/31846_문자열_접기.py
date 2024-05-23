N = int(input())
S = input()

Q = int(input())

for _ in range(Q):
    L, R = map(int, input().split())
    L -= 1
    R -= 1
    T = S[L:R + 1]
    best_score = 0
    
    for i in range(len(T) - 1):
        l = i
        r = i + 1
        score = 0
        
        while l >= 0 and r < len(T):
            if T[l] == T[r]:
                score += 1
            
            l -= 1
            r += 1
                
        best_score = max(best_score, score)
        
    print(best_score)
