import sys
input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush

coin = int(input())
while True:
    if coin % 4 == 0:
        print('3\n')
        coin -= 3
    else:
        print(f'{coin % 4 - 1}\n')
        coin -= coin % 4 - 1
    flush()

    response = input().strip()
    if response == 'I give up':
        break
    coin -= int(response)
