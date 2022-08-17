A = []
B = []

for _ in range(4):
    A.append(int(input()))

for _ in range(2):
    B.append(int(input()))

A.sort(reverse=True)
B.sort(reverse=True)

print(A[0] + A[1] + A[2] + B[0])
