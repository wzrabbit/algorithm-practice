A = int(input())
B = int(input())
C = int(input())
D = int(input())
E = int(input())
F = int(input())

diff = A * 3 + B * 2 + C * 1 - (D * 3 + E * 2 + F * 1)

if diff > 0:
    print('A')
elif diff < 0:
    print('B')
else:
    print('T')
