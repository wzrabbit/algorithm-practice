MAX_SCORES = [100, 100, 200, 200, 300, 300, 400, 400, 500]
scores = list(map(int, input().split()))

score = 0

for i in range(9):
    if scores[i] > MAX_SCORES[i]:
        print('hacker')
        exit()
    
    score += scores[i]

print('draw' if score >= 100 else 'none')
