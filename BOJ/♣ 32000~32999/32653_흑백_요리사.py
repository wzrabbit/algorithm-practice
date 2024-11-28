def get_gcd(a, b):
    if a % b == 0:
        return b
    
    return get_gcd(b, a % b)

def get_lcm(a, b):
    return a * b // get_gcd(a, b)

N = int(input())
arr = list(map(int, input().split()))
lcm = arr[0] * 2

for i in range(1, N):
    lcm = get_lcm(lcm, arr[i] * 2)

print(lcm)
