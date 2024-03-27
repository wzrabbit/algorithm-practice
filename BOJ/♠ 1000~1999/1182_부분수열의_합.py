N, S = map(int, input().split())
arr = list(map(int, input().split()))
answer = 0

for i in range(1, 2**N):
    binary = bin(i)[2:].zfill(N)
    total = 0

    for j in range(N):
        if binary[j] == "1":
            total += arr[j]

    if total == S:
        answer += 1

print(answer)
