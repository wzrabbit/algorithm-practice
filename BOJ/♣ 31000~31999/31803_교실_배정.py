N = int(input())
answer = 1

for i in range(1, N + 1):
    answer *= i
    
for i in range(2, N + 1, 2):
    answer //= i
    
print(answer)
