import sys
input = sys.stdin.readline

N, P, C = map(int, input().split())
contestants = [[-10**18, N]]
answer = [''] * N

for i in range(N):
    contestants.append([int(input()), i])

contestants.sort(reverse=True)

high_cut_line = contestants[P][0] + C
low_cut_line = contestants[P - 1][0]

for i in range(P):
    score, index = contestants[i]
    if score >= high_cut_line:
        answer[index] = 'Pass'
    else:
        answer[index] = 'Short'
        
for i in range(P, N):
    score, index = contestants[i]
    if score + C >= low_cut_line:
        answer[index] = 'Short'
    else:
        answer[index] = 'Fail'
        
print(*answer, sep='\n')
