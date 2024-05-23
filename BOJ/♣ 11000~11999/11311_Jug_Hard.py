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

    if C % get_gcd(A, B) == 0:
        print("Yes\n")
    else:
        print("No\n")
