N = int(input())

for _ in range(N):
    arr = list(map(int, input().split()))
    has_mack = 18 in arr
    has_zack = 17 in arr

    print(*arr)

    if has_zack and has_mack:
        print('both')
    elif has_zack:
        print('zack')
    elif has_mack:
        print('mack')
    else:
        print('none')
    
    print()
