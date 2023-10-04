A = input()
B = ""

if len(A) == 1:
    print(A)
    print(A, 0)
    exit(0)

if A[0] == "1":
    B = (len(A) - 1) * "9"
else:
    B = str(int(A[0]) - 1) + (len(A) - 1) * "9"

C = str(int(A) - int(B))
len_sum = 0

for i in B + C:
    len_sum += int(i)

print(len_sum)
print(B, C)
