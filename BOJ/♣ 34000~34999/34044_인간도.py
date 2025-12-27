N = int(input())

if N == 1:
    print(-1)
elif N % 2 == 0:
    print('2937' * (N // 2))
else:
    print('2937' * ((N - 3) // 2) + '131329')
