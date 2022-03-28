e1, e2 = list(map(int, input().split()))
fx = list(map(int, input().split()))
x0 = int(input())

l = fx[0] * x0 + fx[1]
print(l)

if fx[0] == 0:
    print('0 0')
else:
    x = e1
    y = e2 * abs(fx[0])
    print(x, y)