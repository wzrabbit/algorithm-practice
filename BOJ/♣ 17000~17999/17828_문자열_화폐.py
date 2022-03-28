import sys

length, value = list(map(int, sys.stdin.readline().split()))

if value < length or value > length * 26:
    print('!')
else:
    z = (value - length) // 25
    mid = chr((value - length) % 25 + 65)
    if z == length:
        mid = ''
    a = length - z - 1
    print('A' * a + mid + 'Z' * z)
