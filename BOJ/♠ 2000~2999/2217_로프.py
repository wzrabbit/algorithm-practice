import sys
cases = int(sys.stdin.readline())
ropes = []
maxWeight = 0
mul = 1

for _ in range(cases):
    ropes.append(int(sys.stdin.readline()))
ropes.sort(reverse = True)

for i in range(cases):
    current = ropes[i] * mul
    if current > maxWeight:
        maxWeight = current
    mul += 1

print(maxWeight)