A = input()
B = input()

for i in range(len(A)):
    print(max(int(A[i]), int(B[i])), end="")
