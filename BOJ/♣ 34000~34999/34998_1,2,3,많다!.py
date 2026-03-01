import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    X = int(input())
    exp = input().strip()
    
    if '!' in exp:
        print('!\n')
    else:
        result = eval(exp)

        if result >= 10:
            print('!\n')
        else:
            print(f'{result}\n')
