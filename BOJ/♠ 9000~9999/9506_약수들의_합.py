import sys

input = sys.stdin.readline
print = sys.stdout.write

while True:
    N = int(input())

    if N == -1:
        break

    divisors = []

    for i in range(1, 320):
        if N % i == 0:
            divisors.append(i)
            divisors.append(N // i)

    divisors = list(set(divisors))

    divisors.sort()
    divisors.pop()

    if sum(divisors) == N:
        print(f"{N} = ")

        for i in range(len(divisors)):
            print(f"{divisors[i]}")

            if i != len(divisors) - 1:
                print(" + ")

        print("\n")
    else:
        print(f"{N} is NOT perfect.\n")
