R, C = map(int, input().split())
if R * C % 2 == 0:
    print(0)
else:
    print(min(R, C))
