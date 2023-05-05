N = int(input())
weights = list(map(int, input().split()))
sorted_weights = sorted(weights, reverse=True)
index = 0
score = 0

for i in reversed(range(N)):
    if weights[i] == sorted_weights[index]:
        index += 1
        score += 1

print(N - score)
