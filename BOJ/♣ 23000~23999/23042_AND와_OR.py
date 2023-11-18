N = int(input())
arr = list(map(int, input().split()))
bits_count = [0] * 31
INF = 10**9 + 7

for i in range(N):
    cur = bin(arr[i])[2:].zfill(31)

    for j in range(31):
        bits_count[j] += int(cur[j])

answer = 1

for _ in range(N):
    cur = 0

    for i in range(31):
        if bits_count[i] > 0:
            bits_count[i] -= 1
            cur |= 1 << (30 - i)

    answer = answer * cur % INF

print(answer)
