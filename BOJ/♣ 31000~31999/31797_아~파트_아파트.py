N, M = map(int, input().split())
hands = []

for i in range(M):
    left, right = map(int, input().split())
    hands.append([i + 1, left])
    hands.append([i + 1, right])
    
hands.sort(key=lambda x: x[1])

print(hands[N % (M * 2) - 1][0])
