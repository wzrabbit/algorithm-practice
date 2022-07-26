N = int(input())
game = list(map(int, input().split()))
answer = 0

grundy = game[0]
for i in range(1, N):
    grundy ^= game[i]

if grundy == 0:
    print(0)
else:
    for i in range(N):
        for j in range(1, game[i] + 1):
            if grundy ^ game[i] ^ (game[i] - j) == 0:
                answer += 1
    print(answer)
