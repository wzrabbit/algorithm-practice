A, B, N = map(int, input().split())

if A >= B and A - B >= N * 2 and (A - B) % 2 == 0:
    print("YES")
else:
    print("NO")
