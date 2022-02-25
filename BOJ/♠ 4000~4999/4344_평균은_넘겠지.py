import sys
import math
input = sys.stdin.readline
print = sys.stdout.write

tc = int(input())
for _ in range(tc):
    data = list(map(int, input().split()))
    average = 0
    count = 0

    for i in range(1, data[0] + 1):
        average += data[i]
    average = average / data[0]

    for i in range(1, data[0] + 1):
        if data[i] > average:
            count += 1
    print('{:.3f}%'.format(count * 100 / data[0]) + '\n')
