T = int(input())

for _ in range(T):
    N = int(input())
    arr = []

    for __ in range(N):
        name, amount = input().split()
        amount = int(amount)
        
        arr.append((name, amount))

    arr.sort(key=lambda x: x[1], reverse=True)
    print(arr[0][0])
