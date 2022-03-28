import sys
input = sys.stdin.readline
length, start = list(map(int, input().split(' ')))
data = list(map(int, input().split(' ')))

for i in range(length):
    data[i] = abs(start - data[i])


def gcd(a, b):
    if a < b:
        a, b = b, a
    while True:
        c = a % b
        if c == 0:
            return b
        else:
            a, b = b, c


result = data[0]
for i in range(1, length):
    result = gcd(result, data[i])
print(result)
