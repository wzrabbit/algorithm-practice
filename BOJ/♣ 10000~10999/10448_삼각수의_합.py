import sys
input = sys.stdin.readline

T = int(input())
answer = [0] * 1001

for i in range(1, 46):
        for j in range(i, 46):
            for k in range(j, 46):
                cur = (i * (i + 1) + j * (j + 1) + k * (k + 1)) // 2

                if cur <= 1000:
                    answer[cur] = 1

for _ in range(T):
    N = int(input())
    print(answer[N])
