import sys
x, y, a, b = list(map(int, sys.stdin.readline().split(' ')))
time = 0

if a * 2 > b:
    time += min(x, y) * b
else:
    time += min(x, y) * a * 2

time += (abs(x - y) // 2) * min(a * 2, b * 2) + (abs(x - y) % 2) * a 

print(time)