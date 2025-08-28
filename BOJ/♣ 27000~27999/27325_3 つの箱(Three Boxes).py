N = int(input())
S = input()
answer = 0
pos = 1

for cur in S:
    if cur == 'L':
        pos = max(1, pos - 1)
    else:
        pos = min(3, pos + 1)
    
    if pos == 3:
        answer += 1

print(answer)
