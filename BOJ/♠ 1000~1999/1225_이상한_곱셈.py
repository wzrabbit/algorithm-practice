import sys
input = sys.stdin.readline

A, B = input().strip().split()
A = list(map(int, list(A)))
B = list(map(int, list(B)))
sum_ = 0

for a in A:
    for b in B:
        sum_ += a * b

print(sum_)
