import math

n = int(input())
success = False

for i in range(1, math.floor(math.sqrt(n)) + 1):
    j = n // i
    if n % i == 0 and (j - i) % 2 == 0:
        success = True
        print((j + i) // 2, (j - i) // 2)
        break

if not success:
    print('impossible')
