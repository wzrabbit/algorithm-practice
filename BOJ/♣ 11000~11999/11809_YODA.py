A = input()
B = input()

max_len = max(len(A), len(B))
A = list(A.zfill(max_len))
B = list(B.zfill(max_len))

for i in range(max_len):
    if A[i] < B[i]:
        A[i] = '_'
    elif A[i] > B[i]:
        B[i] = '_'

A = ''.join(A)
B = ''.join(B)

A = A.replace('_', '')
B = B.replace('_', '')

print('YODA' if A == '' else int(A))
print('YODA' if B == '' else int(B))
