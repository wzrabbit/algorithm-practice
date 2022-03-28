import sys
input = sys.stdin.readline
n = list(map(int, input().split()))[0]
seat = [False] * (n + 2)
count = 0

data = list(map(int, input().split()))
for i in data:
    seat[i] = True

for i in range(1, n + 1):
    l = i - 1
    r = i + 1
    if l == 0:
        l = n
    if r == n + 1:
        r = 1

    if seat[i] == False and seat[l] == False and seat[r] == False:
        seat[i] = True
        count += 1

print(count)
