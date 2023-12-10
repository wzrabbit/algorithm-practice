A, B = input().split()
max_len = max(len(A), len(B))

A = A.zfill(max_len)
B = B.zfill(max_len)

answer = ""

for i in range(max_len):
    answer += str(int(A[i]) + int(B[i]))

print(answer)
