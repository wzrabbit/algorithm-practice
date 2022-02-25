import sys
print = sys.stdout.write
num = int(input())
div = 2

while num > 1:
    if num % div == 0:
        num //= div
        print(str(div) + '\n')
    else:
        div += 1
