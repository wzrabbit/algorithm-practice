import sys
input = sys.stdin.readline

N = int(input())
answer = 0

for _ in range(N):
    data = input().split()
    command = data[1]
    amount = int(data[2])
    
    if command == 'IN':
        answer += amount
    else:
        answer -= amount

if answer > 0:
    print(answer)
else:
    print('NO STRAGGLERS')
