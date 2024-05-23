N = int(input())
money, goal = map(int, input().split())

for _ in range(N):
    price, atk = map(int, input().split())
    
    if price <= money and atk > goal:
        print('YES')
        exit(0)
        
print('NO')
