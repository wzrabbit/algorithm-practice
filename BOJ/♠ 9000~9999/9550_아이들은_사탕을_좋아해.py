T = int(input())

for _ in range(T):
    N, K = map(int, input().split())
    arr = list(map(int, input().split()))
    answer = 0

    for i in range(N):
        answer += arr[i] // K

    print(answer)
