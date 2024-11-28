N, K, T = map(int, input().split())
D = list(map(int, input().split()))
anger = 0

for i in range(N):
    if T > K:
        T = T + D[i] - abs(T - K)
    elif T < K:
        T = T + D[i] + abs(T - K)
    else:
        T = T + D[i]

    anger += abs(T - K)

print(anger)
