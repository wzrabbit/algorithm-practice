import sys
import random
input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush


def get_random():
    return int(random.random() * 2) + 1


num = 0
while True:
    if num % 3 == 0:
        num += get_random()
    elif num % 3 == 1:
        num += 2
    else:
        num += 1

    print(f'{num}\n')
    flush()

    if num >= 99:
        break

    num = int(input())
