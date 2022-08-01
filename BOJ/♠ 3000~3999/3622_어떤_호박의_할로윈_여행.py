A, a, B, b, P = map(int, input().split())

if (A + B <= P) or (A <= P and B <= a) or (B <= P and A <= b):
    print('Yes')
else:
    print('No')
