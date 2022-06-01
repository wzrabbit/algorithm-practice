n = int(input())
sieve = [True] * 7400000

for i in range(2, 2800):
    if sieve[i] == True:
        for j in range(i * 2, 7400000, i):
            sieve[j] = False

count = 0
for i in range(2, 7400000):
    if sieve[i] == True:
        count += 1
        if count == n:
            print(i)
            break
