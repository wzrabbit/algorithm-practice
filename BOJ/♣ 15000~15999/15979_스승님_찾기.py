r, c = map(int, input().split())
r = abs(r)
c = abs(c)


def gcd(a, b):
    while b != 0:
        tmp = a % b
        a = b
        b = tmp
    return a


if [r, c] == [0, 0]:
    print(0)
elif r == 0 and c != 0:
    if c == 1:
        print(1)
    else:
        print(2)
elif r != 0 and c == 0:
    if r == 1:
        print(1)
    else:
        print(2)
elif gcd(r, c) == 1:
    print(1)
else:
    print(2)
