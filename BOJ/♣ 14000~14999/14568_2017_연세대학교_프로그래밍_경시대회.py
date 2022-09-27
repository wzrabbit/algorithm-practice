N = int(input())
cnt = 0

for i in range(2, N - 3, 2):
    for j in range(3, N - i):
        k = N - i - j
        if j >= k + 2:
            cnt += 1

print(cnt)
