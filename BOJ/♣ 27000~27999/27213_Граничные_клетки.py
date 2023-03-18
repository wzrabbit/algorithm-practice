R = int(input())
C = int(input())

if R == 1 or C == 1:
    print(R * C)
else:
    print(R * 2 + C * 2 - 4)