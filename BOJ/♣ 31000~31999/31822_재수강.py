S = input()
N = int(input())
answer = 0

for _ in range(N):
    cur = input()
    if cur[:5] == S[:5]:
        answer += 1
        
print(answer)
