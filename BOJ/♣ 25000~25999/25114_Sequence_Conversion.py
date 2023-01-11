import sys
input = sys.stdin.readline

N = int(input())
before = list(map(int, input().split()))
after = list(map(int, input().split()))
count = 0

for i in range(N - 1):
    if before[i] == after[i]:
        continue

    karma = before[i] ^ after[i]
    before[i + 1] ^= karma
    count += 1

if before[-1] == after[-1]:
    print(count)
else:
    print(-1)
