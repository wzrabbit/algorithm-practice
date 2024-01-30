def factorize(num):
    result = dict()

    for i in range(2, 100001):
        if num == 1:
            break

        if num % i != 0:
            continue

        result[i] = 0

        while num % i == 0:
            num //= i
            result[i] += 1

    if num > 1:
        result[num] = 1

    return result


a, b, L = map(int, input().split())
a = factorize(a)
b = factorize(b)
L = factorize(L)
c = dict()

for num, count in list(a.items()) + list(b.items()):
    if num not in L or count > L[num]:
        print(-1)
        exit(0)

    if num not in c:
        c[num] = L[num]

    if count == L[num]:
        c[num] = 0
        continue

for num, count in L.items():
    if num not in c:
        c[num] = count

answer = 1

for num, count in c.items():
    answer *= num**count

print(answer)
