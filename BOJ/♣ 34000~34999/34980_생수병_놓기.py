N = int(input())
S = input()
T = input()
S_count = S.count('w')
T_count = T.count('w')

if S_count > T_count:
    print('Oryang')
elif S_count == T_count and S != T:
    print('Its fine')
elif S_count < T_count:
    print('Manners maketh man')
else:
    print('Good')
