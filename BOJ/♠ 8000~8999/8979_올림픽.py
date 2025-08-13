N, K = map(int, input().split())
arr = []

for i in range(1, N + 1):
    arr.append(tuple(map(int, input().split())))

arr.sort(key=lambda x: x[1:], reverse=True)

rank = 1
tie = 0

for i in range(N):
    if i >= 1:
        if arr[i][1:] == arr[i - 1][1:]:
            tie += 1
        else:
            rank += tie + 1
            tie = 0
    
    if arr[i][0] == K:
        print(rank)
        break
