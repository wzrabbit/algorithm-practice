N = int(input())
S = input()
c_positions = []
p_positions = []

for i in range(N):
    if S[i] == 'P':
        p_positions.append(i)
    elif S[i] == 'C':
        c_positions.append(i)
        
for i in range(min(len(c_positions), len(p_positions))):
    c_positions[i], p_positions[i] = p_positions[i], c_positions[i]

for i in range(N):
    if i in c_positions:
        print('C', end="")
    elif i in p_positions:
        print('P', end="")
    else:
        print(S[i],end="")
