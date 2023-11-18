import sys

input = sys.stdin.readline

N, K, C, R = map(int, input().split())
base = list(map(int, input().split()))
s = list(map(int, input().split()))
cost = list(map(int, input().split()))
skill = [0] * N

stardust = 0
fatigue = 0
combo = 0

for i in range(N):
    magic_no = int(input())

    if magic_no == 0:
        fatigue = max(0, fatigue - R)
        combo = 0
        continue

    magic_no -= 1

    stardust += (
        base[magic_no]
        * (100 + combo * C)
        * (100 + skill[magic_no] * s[magic_no])
        // 10000
    )

    fatigue += cost[magic_no]
    combo += 1
    skill[magic_no] += 1

    if fatigue > 100:
        stardust = -1
        break

print(stardust)
