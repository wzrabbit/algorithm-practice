import sys
input = sys.stdin.readline

N = int(input())
arr = []
wa_left = [0] * (N + 1)

for i in range(N):
    cur_wa_left = int(input())
    arr.append([cur_wa_left, i + 1])
    wa_left[i + 1] = cur_wa_left

ac = []
wa = []

for i in range(N):
    if arr[i][0] == 0:
        ac.append(arr[i][1])
    else:
        wa.append(arr[i][1])

answer = []
success = True

for i in range(2 * N - 1):
    if i % 2 == 0:
        if len(ac) == 0:
            success = False
            break
        
        answer.append(ac.pop())
        continue

    if len(wa) == 0:
        success = False
        break

    cur = wa[-1]
    answer.append(cur)
    wa_left[cur] -= 1

    if wa_left[cur] == 0:
        wa.pop()
        ac.append(cur)

if success:
    print(*answer, sep="\n")
else:
    print(-1)
