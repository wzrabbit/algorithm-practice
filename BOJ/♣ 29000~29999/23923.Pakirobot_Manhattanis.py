N = int(input())
S = input()

print(abs(S.count('N') - S.count('S')) + abs(S.count('E') - S.count('W')))
