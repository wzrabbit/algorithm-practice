A = int(input())
M, N = map(int, input().split())

print(min(M / A * 2, N / A * 2, max(M / A, N), max(M, N / A)))
