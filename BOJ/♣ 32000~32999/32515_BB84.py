N = int(input())
A = input()
B = input()
C = input()
D = input()
success = True
key = []

for i in range(N):
    if A[i] == C[i]:
        if B[i] == D[i]:
            key.append(B[i])
        else:
            success = False
            break

if success:
    print("".join(key))
else:
    print("htg!")
