t = int(input())
a, b, c, d = map(int, input().split())

if a * t + b == c * t + d:
    print('Yes', a * t + b)
else:
    print('No')
