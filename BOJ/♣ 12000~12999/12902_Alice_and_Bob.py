def gcd(a, b):
    if a % b == 0:
        return b

    return gcd(b, a % b)


N = int(input())
arr = list(map(int, input().split()))

div = gcd(arr[0], arr[1])
for i in range(2, N):
    div = gcd(div, arr[i])

moves = max(arr) // div - N

if moves % 2 == 0:
    print('Bob')
else:
    print('Alice')
