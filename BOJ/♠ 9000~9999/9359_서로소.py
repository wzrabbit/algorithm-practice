import math

t = int(input())
for o in range(t):
    start, end, num = map(int, input().split())
    answer = end - start + 1
    n = num
    div = []

    for i in range(2, math.ceil(num ** 0.5) + 1):
        if n % i == 0:
            div.append(i)
            while n % i == 0:
                n //= i
    if n not in div and n != 1:
        div.append(n)

    r = len(div)

    for i in range(1, 2 ** r):
        bit = bin(i)[2:].zfill(r)
        rep = 1
        cnt = 0

        for j in range(r):
            if bit[j] == '1':
                rep *= div[j]
                cnt += 1

        if cnt % 2 == 0:
            answer += end // rep - (start - 1) // rep
        else:
            answer -= end // rep - (start - 1) // rep

    print(f'Case #{o + 1}: {answer}')
