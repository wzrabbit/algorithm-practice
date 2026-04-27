A, B, C, D = map(int, input().split())

if A == D and B == C:
    print('JAH')
    print(A, B, C, D)
    exit()

if A == D:
    print('JAH')
    print(A, B, B, D)
    exit()

if B == C:
    print('JAH')
    print(A, B, C, A)
    exit()

print('EI')
