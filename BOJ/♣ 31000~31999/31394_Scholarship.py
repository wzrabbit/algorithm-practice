scores = []

N = int(input())

for _ in range(N):
    scores.append(int(input()))

if 3 in scores:
    print("None")
    exit(0)

if scores.count(5) == N:
    print("Named")
    exit(0)

average = sum(scores) / N

if average >= 4.5:
    print("High")
    exit(0)

print("Common")
