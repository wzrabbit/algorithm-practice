import math

N, M = map(int, input().split())
gcd = math.gcd(N, M)

print(f'{N // gcd}/{M // gcd}')
