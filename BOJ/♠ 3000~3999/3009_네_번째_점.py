x = []
y = []

for _ in range(3):
    new_x, new_y = map(int, input().split())
    x.append(new_x)
    y.append(new_y)

x.sort()
y.sort()

if x[0] == x[1]:
    print(x[2], end=' ')
else:
    print(x[0], end=' ')

if y[0] == y[1]:
    print(y[2])
else:
    print(y[0])
