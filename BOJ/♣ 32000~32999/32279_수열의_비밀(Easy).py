N = int(input())
p, q, r, s = map(int, input().split())
A = [0, int(input())]

for i in range(2, N + 1):
    if i % 2 == 0:
        A.append(p * A[i // 2] + q)
    else:
        A.append(r * A[i // 2] + s)

print(sum(A))
