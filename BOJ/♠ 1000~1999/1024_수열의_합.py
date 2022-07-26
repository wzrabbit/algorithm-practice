N, M = map(int, input().split())
success = False

for i in range(M, 101):
    A = i * (i - 1) // 2
    if (N - A) % i == 0 and N - A >= 0:
        key = (N - A) // i
        success = True

        for j in range(i):
            print(key + j, end=' ')

        break

if not success:
    print('-1')
