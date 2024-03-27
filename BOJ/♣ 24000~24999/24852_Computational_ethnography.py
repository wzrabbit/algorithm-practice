import math

L = int(input())
R = int(input())
answer = 0

for i in range(1, 10**6):
    if L <= i**2 <= R and i**2 % 10 != 0 and math.sqrt(int(str(i**2)[::-1])) % 1 == 0:
        answer += 1

print(answer)
