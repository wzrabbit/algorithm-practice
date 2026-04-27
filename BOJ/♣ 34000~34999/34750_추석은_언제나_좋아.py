N = int(input())

if N >= 1000000:
    print(N // 100 * 20, N // 100 * 80)
elif N >= 500000:
    print(N // 100 * 15, N // 100 * 85)
elif N >= 100000:
    print(N // 100 * 10, N // 100 * 90)
else:
    print(N // 100 * 5, N // 100 * 95)
