n, m = map(int, input().split())
prime = list(map(int, input().split()))
answer = 0

for i in range(1, 2 ** n):
    bit = bin(i)[2:].zfill(n)
    lcm = 1
    cnt = 0

    for j in range(n):
        if bit[j] == '1':
            lcm *= prime[j]
            cnt += 1

    if cnt % 2 == 0:
        answer -= m // lcm
    else:
        answer += m // lcm

print(answer)
