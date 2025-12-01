A, B = map(int, input().split())

if A == 0 and B == 0:
    print('Not a moose')
elif A == B:
    print(f'Even {A * 2}')
else:
    print(f'Odd {max(A, B) * 2}')
