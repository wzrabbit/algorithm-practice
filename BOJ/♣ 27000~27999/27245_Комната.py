W = int(input())
L = int(input())
H = int(input())

if min(W, L) >= H * 2 and max(W, L) <= min(W, L) * 2:
    print('good')
else:
    print('bad')
