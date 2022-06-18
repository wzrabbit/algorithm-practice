import sys
input = sys.stdin.readline
print = sys.stdout.write

n, karma, current = map(int, input().split())
karma = karma // 2 + 1
current -= 1

while True:
    inp = int(input())
    if inp == karma:
        print('0\n')
        break

    current = (current + inp - karma) % n
    print(str(current + 1) + '\n')
