N = int(input())

for _ in range(N):
    num, check = map(int, input().split())
    bit_count = bin(num)[2:].count("1")

    if bit_count % 2 == check:
        print("Valid")
    else:
        print("Corrupt")
