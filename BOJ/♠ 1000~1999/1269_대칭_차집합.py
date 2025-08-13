N, M = map(int, input().split())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

print(len(set(A + B)) * 2 - N - M)
