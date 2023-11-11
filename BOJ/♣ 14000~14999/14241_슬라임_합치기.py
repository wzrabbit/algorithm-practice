N = int(input())
slimes = list(map(int, input().split()))
score = 0

for i in range(N - 1):
    slimes.sort()
    a = slimes.pop()
    b = slimes.pop()
    slimes.append(a + b)
    score += a * b

print(score)
