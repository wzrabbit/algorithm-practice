L, N = map(int, input().split())
arr = []
answer = 0

for _ in range(N):
    arr.append(int(input()))

for i in range(1 << N):
    binary = bin(i)[2:].zfill(N)
    cur = 0

    for j in range(N):
        if binary[j] == '1':
            cur += arr[j]

    if cur <= L:
        answer = max(answer, cur)

print(answer)
