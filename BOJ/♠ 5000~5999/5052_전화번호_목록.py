import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())
for _ in range(T):
    N = int(input())
    numbers = []
    success = True
    
    for __ in range(N):
        numbers.append(input().rstrip())
    
    numbers.sort()
    
    for i in range(N - 1):
        min_len = min(len(numbers[i]), len(numbers[i + 1]))
        if numbers[i][:min_len] == numbers[i + 1][:min_len]:
            success = False
            break
        
    if success:
        print('YES\n')
    else:
        print('NO\n')