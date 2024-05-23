import sys

input = sys.stdin.readline
print = sys.stdout.write


def get_gcd(a, b):
    if a % b == 0:
        return b

    return get_gcd(b, a % b)


T = int(input())

for _ in range(T):
    A, B, C = map(int, input().split())

    if A < C and B < C:
        print("NO\n")
        continue

    if C % get_gcd(A, B) == 0:
        print("YES\n")
    else:
        print("NO\n")
