a, b, c = sorted(map(int, input().split()))

if a == b == c:
    print(2)
elif a ** 2 + b ** 2 == c ** 2:
    print(1)
else:
    print(0)
