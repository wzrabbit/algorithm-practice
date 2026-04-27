A, B, C, D = map(int, input().split())
shuttle_ok = A + B <= D
walk_ok = C <= D

if shuttle_ok and walk_ok:
    print('~.~')
elif shuttle_ok:
    print('Shuttle')
elif walk_ok:
    print('Walk')
else:
    print('T.T')
