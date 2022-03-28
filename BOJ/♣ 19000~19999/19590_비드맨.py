import sys
input = sys.stdin.readline
num = int(input())
total = 0
mx = 0
for _ in range(num):
    current = int(input())
    total += current
    if mx < current:
        mx = current
total -= mx

if total < mx:
    print(mx - total)
elif (total + mx) % 2 == 1:
    print(1)
else:
    print(0)
