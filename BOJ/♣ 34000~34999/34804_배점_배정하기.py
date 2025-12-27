import sys
input = sys.stdin.readline

N, M = map(int, input().split())
scores = set()
has_same_score = False

for i in range(N):
    arr = list(map(int, input().split()))[1:]
    score = 0

    for j in range(len(arr)):
        score += 2 ** (arr[j] - 1)
    
    if score in scores:
        has_same_score = True
        break
    
    scores.add(score)

if has_same_score:
    print(-1)
    exit()

for i in range(M):
    print(2 ** i, end=' ')
