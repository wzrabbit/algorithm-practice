T = int(input())

for _ in range(T):
    N = int(input())
    answer = 0
    cur = 0

    for _ in range(N):
        A, B = map(int, input().split())
        cur += A - B
        answer = min(answer, cur)
    
    print(-answer)
