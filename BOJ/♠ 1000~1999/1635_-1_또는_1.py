import sys
input = sys.stdin.readline
print = sys.stdout.write

N, Q = map(int, input().split())
for _ in range(Q):
    answer = ['1'] * N
    arr = list(map(int, input().split()))
    total = sum(arr)

    for i in range(N):
        if total == 0:
            break

        answer[i] = '-1'
        if arr[i] == 1:
            total -= 2
        else:
            total += 2

    print(' '.join(answer) + '\n')
