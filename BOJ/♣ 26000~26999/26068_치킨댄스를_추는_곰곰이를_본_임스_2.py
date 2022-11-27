T = int(input())
cnt = 0

for _ in range(T):
    day = int(input().split('-')[1])
    if day <= 90:
        cnt += 1
        
print(cnt)