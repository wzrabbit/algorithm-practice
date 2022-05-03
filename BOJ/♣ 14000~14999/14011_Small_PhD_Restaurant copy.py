import sys
input = sys.stdin.readline

n, money = map(int, input().split())
cost = list(map(int, input().split()))
award = list(map(int, input().split()))
arr = []

for i in range(n):
    if cost[i] >= award[i]:
        continue
    arr.append((cost[i], award[i]))

arr.sort(key=lambda x: x[0])

for i in range(len(arr)):
    if money >= arr[i][0]:
        money = money - arr[i][0] + arr[i][1]
    else:
        break

print(money)
