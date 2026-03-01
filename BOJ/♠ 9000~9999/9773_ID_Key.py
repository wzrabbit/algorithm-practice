T = int(input())

for _ in range(T):
    S = input()
    result = sum(map(int, list(S))) + int(S[-3:]) * 10

    if result < 1000:
        result += 1000

    if result >= 10000:
        result = str(result % 10000).zfill(4)

    print(result)
