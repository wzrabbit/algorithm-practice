N = int(input())
A = int(input())
B = int(input())
C = int(input())
times = 0

assert(A <= 35 and B <= 100 and C <= 10)

while True:
    if N == 0:
        break
    
    N -= 1
    A += 1
    times += 1

    if A == 35:
        N += 30
        A = 0

    if N == 0:
        break

    N -= 1
    B += 1
    times += 1

    if B == 100:
        N += 60
        B = 0

    if N == 0:
        break

    N -= 1
    C += 1
    times += 1

    if C == 10:
        N += 9
        C = 0

print(f'Martha plays {times} times before going broke.')
