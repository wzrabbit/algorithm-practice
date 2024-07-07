import sys
input = sys.stdin.readline
print = sys.stdout.write

T = int(input())

for _ in range(T):
    L, R = map(int, input().split())

    if R >= 4:
        print(f'{R}\n')
        continue

    number = ''

    for i in range(L, R + 1):
        number += str(1 << i)

    number = int(number)
    answer = 0

    while number % 2 == 0:
        answer += 1
        number >>= 1

    print(f'{answer}\n')
