C = int(input())
N = 1

while True:
    if C == 1:
        break

    if C % 2 == 1:
        C = 3 * C + 1
    else:
        C //= 2

    N += 1

print(N)
