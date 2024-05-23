N, M = map(int, input().split())
db = dict()

for _ in range(N):
    word, meaning = input().split()
    db[word] = meaning
    
for _ in range(M):
    S = input()
    result = []
    buf = []
    
    for i in range(len(S)):
        for j in range(i + 1, len(S) + 1):
            cur = S[i:j]
            
            if cur in db:
                buf.append(cur)
                
        buf.sort()
    
        for i in buf:
            result.append(db[i])
        
        buf = []
    
    if len(result) == 0:
        print(-1)
    else:
        print(''.join(result))
