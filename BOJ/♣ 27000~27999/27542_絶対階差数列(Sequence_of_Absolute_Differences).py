N = int(input())
before = list(map(int, input().split()))
current = []

for _ in range(N - 1):
    for i in range(len(before) - 1):
        current.append(abs(before[i] - before[i + 1]))
    before = []
    current, before = before, current
    
print(before[0])
