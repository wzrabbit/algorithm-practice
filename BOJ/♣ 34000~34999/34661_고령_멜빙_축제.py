T = int(input())

for _ in range(T):
    R, C = map(int, input().split())
    space_count = sum([input().count('.') for _ in range(R)])
    
    if space_count % 2 == 1:
        print('sewon')
    else:
        print('pizza')

