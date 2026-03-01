U, O, S = map(int, input().split())
matched = max(0, (U - S) // 3)
U -= matched * 2
S += matched

print(min(U, O, S))
