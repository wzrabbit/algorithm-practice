n = int(input())
ans = 1

while n >= 1:
    ans = ans * n % (1e9 + 7)
    n -= 2

print(ans)
