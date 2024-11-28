N, A, B = map(int, input().split())
good = 1
bad = 1

for _ in range(N):
    good += A
    bad += B

    if good < bad:
        good, bad = bad, good
    elif good == bad:
        bad -= 1

print(good, bad)
