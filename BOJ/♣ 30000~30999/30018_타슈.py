N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))
total = 0

for i in range(N):
    total += abs(A[i] - B[i])

print(total // 2)
