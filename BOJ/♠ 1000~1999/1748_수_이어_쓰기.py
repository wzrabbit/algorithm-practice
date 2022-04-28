n = int(input())
karma = 9
mul = 1
ans = 0

while True:
    if n >= karma:
        ans += karma * mul
        n -= karma
        mul += 1
        karma *= 10
    else:
        ans += n * mul
        break

print(ans)
