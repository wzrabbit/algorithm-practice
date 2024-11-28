N = int(input())
A, B = map(int, input().split())

if A + B <= N:
    print(int("1" * (A + B) + "0" * (N - A - B), 2))
else:
    exceeded = A + B - N
    one_count = N - exceeded
    print(int("1" * one_count + "0" * (N - one_count), 2))
