import math

E = int(input())
sieve = [True] * 1001

for i in range(2, 35):
    if not sieve[i]:
        continue

    for j in range(i * 2, 1001, i):
        sieve[j] = False

cnt = 1
cur = 2
while (E > 1000 or not sieve[E]) and cur <= 1000:
    if not sieve[cur]:
        cur += 1
    elif E % cur == 0:
        E //= cur
        cnt += 1
    else:
        cur += 1

print(math.ceil(math.log2(cnt)))
