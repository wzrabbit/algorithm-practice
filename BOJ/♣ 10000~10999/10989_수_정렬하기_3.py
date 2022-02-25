import sys
input = sys.stdin.readline
print = sys.stdout.write
repeat = int(input())
storage = [0] * 10001

for i in range(repeat):
    storage[int(input())] += 1

for i in range(10001):
    if storage[i] != 0:
        for j in range(storage[i]):
            print(str(i) + '\n')
