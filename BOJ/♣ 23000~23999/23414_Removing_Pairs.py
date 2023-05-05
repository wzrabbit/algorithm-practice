T = input()
S = input()
t_index = 0
s_index = 0

while t_index < len(T) and s_index < len(S):
    if S[s_index] == T[t_index]:
        s_index += 1
        t_index += 1
    else:
        s_index += 2
        
if t_index == len(T) and (len(S) - len(T)) % 2 == 0:
    print('YES')
else:
    print('NO')
