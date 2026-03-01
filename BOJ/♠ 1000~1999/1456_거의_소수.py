A, B = map(int, input().split())
is_prime = [True] * 10000001

for i in range(2, 3200):
    if is_prime[i]:
        for j in range(i * i, 10000001, i):
            is_prime[j] = False

answer = 0

for i in range(2, 10000001):
    if not is_prime[i]:
        continue
    for j in range(2, 65):
        cur = i ** j
        if A <= cur <= B:
            answer += 1
        
        if cur > B:
            break

print(answer)
