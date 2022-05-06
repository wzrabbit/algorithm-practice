import sys
print = sys.stdout.write

n = int(input())
l = 1
r = n - 1
turn = True

while l <= r:
    if turn:
        print(str(l) + ' ')
        l += 1
        turn = not turn
    else:
        print(str(r) + ' ')
        r -= 1
        turn = not turn

print(str(n))
