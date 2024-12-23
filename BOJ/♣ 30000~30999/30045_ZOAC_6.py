N = int(input())
answer = 0

for _ in range(N):
    S = input()
    
    if "01" in S or "OI" in S:
        answer += 1

print(answer)
