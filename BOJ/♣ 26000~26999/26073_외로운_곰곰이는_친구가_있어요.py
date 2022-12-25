import sys
input = sys.stdin.readline
print = sys.stdout.write


def gcd(a, b):
    if a % b == 0:
        return b
    return gcd(b, a % b)


N = int(input())
for _ in range(N):
    R, C = map(int, input().split())
    gcd_bundle = list(map(int, input().split()))
    gcd_result = gcd_bundle[1]

    for i in range(2, len(gcd_bundle)):
        gcd_result = gcd(gcd_result, gcd_bundle[i])

    if R % gcd_result == 0 and C % gcd_result == 0:
        print('Ta-da\n')
    else:
        print('Gave up\n')
