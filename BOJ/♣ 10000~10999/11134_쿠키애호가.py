T = int(input())

for _ in range(T):
    N, C = map(int ,input().split())
    answer = N // C
    
    if N % C != 0:
        answer += 1

    print(answer)
