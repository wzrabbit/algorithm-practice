T = int(input())

for _ in range(T):
    r, e, c = map(int, input().split())
    
    if r > e - c:
        print('do not advertise')
    elif r < e - c:
        print('advertise')
    else:
        print('does not matter')
