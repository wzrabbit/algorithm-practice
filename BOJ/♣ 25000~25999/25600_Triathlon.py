N = int(input())
max_score = 0

for _ in range(N):
    a, d, g = map(int, input().split())
    
    if a == d + g:
        max_score = max(max_score, a * (d + g) * 2)
    else:
        max_score = max(max_score, a * (d + g))

print(max_score)
