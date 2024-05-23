N, M, K = map(int, input().split())
K -= 1
score = [0] * N
status = []

for _ in range(M):
    A, B, result = map(int, input().split())
    A -= 1
    B -= 1
    
    if result == 0:
        status.append([A, B])
    elif result == 1:
        score[A] += 1
    else:
        score[B] += 1

init_best_score = max(score)
init_best_player = score.index(init_best_score)
init_has_candidate = score.count(init_best_score) >= 2
answer = 0

for i in range(1 << len(status)):
    binary = bin(i)[2:].zfill(len(status))
    rollback = []
    best_player = init_best_player
    best_score = init_best_score
    has_candidate = init_has_candidate
    
    for j in range(len(status)):
        winner = None
        if binary[j] == '1':
            winner = status[j][0]
        else:
            winner = status[j][1]
        
        score[winner] += 1
        rollback.append(winner)
        
        if best_score == score[winner]:
            has_candidate = True
        
        if best_score < score[winner]:
            best_player = winner
            best_score = score[winner]
            has_candidate = False
            
    if best_player == K and not has_candidate:
        answer += 1
        
    for cur in rollback:
        score[cur] -= 1
    
print(answer)
