import sys
input = sys.stdin.readline

n = int(input())
count = [0] * 100001
arr = list(map(int, input().split()))
income = 0

for i in arr:
    count[i] += 1

for i in range(1, 100001):
    while count[i] >= 1:
        combo = 0
        for j in range(i, 100001):
            if count[j] >= 1:
                count[j] -= 1
                combo += 1
            else:
                break

        income += combo * (i + combo - 1)

print(income)
