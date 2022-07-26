T = int(input())

for _ in range(T):
    N = int(input())
    arr = list(map(int, input().split()))
    all_minus = True

    for i in range(N):
        if arr[i] >= 0:
            all_minus = False
            break

    # 전부 음수면 그냥 리스트 중 제일 큰 값 하나가 최적
    if all_minus:
        print(max(arr))
        continue

    # 짝수 인덱스가 시작점일 경우
    best = 0
    curr = 0
    reset = True
    idx = 0

    while idx < N:
        if reset:
            curr = arr[idx]
            idx += 2
            best = max(best, curr)
            reset = False
        else:
            if curr + arr[idx - 1] + arr[idx] < arr[idx]:
                reset = True
                continue
            else:
                curr += arr[idx - 1] + arr[idx]
                idx += 2
                best = max(best, curr)

    # 홀수 인덱스가 시작점일 경우
    curr = 0
    reset = True
    idx = 1

    while idx < N:
        if reset:
            curr = arr[idx]
            idx += 2
            best = max(best, curr)
            reset = False
        else:
            if curr + arr[idx - 1] + arr[idx] < arr[idx]:
                reset = True
                continue
            else:
                curr += arr[idx - 1] + arr[idx]
                idx += 2
                best = max(best, curr)

    print(best)
