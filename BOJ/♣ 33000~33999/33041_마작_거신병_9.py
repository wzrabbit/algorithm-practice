import sys
input = sys.stdin.readline
debug = print
print = sys.stdout.write

INF = 10 ** 9

N = int(input())
sizes = list(map(int, input().split()))
one_count, nine_count = map(int, input().split())
state = [0] * N

for i in range(1, N):
    prev = sizes[i - 1] + state[i - 1] * 8
    cur = sizes[i]

    if prev < cur:
        continue

    need_value = prev - cur + 1
    need_nine_count = (need_value + 7) // 8

    if need_nine_count > sizes[i]:
        print("-1")
        exit()

    state[i] = need_nine_count

nine_count -= sum(state)

if nine_count < 0:
    print("-1")
    exit()

sizes.append(INF)
state.append(INF)

for i in range(N - 1, -1, -1):
    if nine_count == 0:
        break

    nxt = sizes[i + 1] + state[i + 1] * 8
    cur = sizes[i] + state[i] * 8

    limit_nine_count = sizes[i] - state[i]
    possible_nine_count = (nxt - cur - 1) // 8

    matched = min(limit_nine_count, possible_nine_count, nine_count)
    nine_count -= matched
    state[i] += matched

if nine_count > 0:
    print("-1")
    exit()

for i in range(N):
    print("9 " * state[i] + "1 " * (sizes[i] - state[i]) + "\n")
