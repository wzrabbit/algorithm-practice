A, B, C = sorted(list(map(int, input().split())))

if A + B == C:
    print(1)
elif A * B == C:
    print(2)
else:
    print(3)
