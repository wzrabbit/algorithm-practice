N, M = map(int, input().split())
P = []
Q = []

for _ in range(N):
    P.append(list(map(int, input().split())))

for _ in range(M):
    Q.append(list(map(int, input().split())))

longest_line = 0

for i in range(N):
    for j in range(M):
        longest_line = max(
            longest_line,
            abs(P[i][0] - Q[j][0]) ** 2 + abs(P[i][1] - Q[j][1]) ** 2,
        )

print(longest_line)
