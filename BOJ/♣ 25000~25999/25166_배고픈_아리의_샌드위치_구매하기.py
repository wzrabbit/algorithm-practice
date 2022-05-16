import sys
input = sys.stdin.readline

sand, kugi = map(int, input().split())

if sand <= 1023:
    print('No thanks')
elif sand >= 2047:
    print('Impossible')
else:
    sand -= 1023
    need = bin(sand)[2:].zfill(10)
    kugi = bin(kugi)[2:].zfill(10)
    success = True

    for i in range(10):
        if need[i] == '1' and kugi[i] == '0':
            success = False
            break

    if success:
        print('Thanks')
    else:
        print('Impossible')
