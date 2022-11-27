T = int(input())
for _ in range(T):
    N = int(input())
    result = 0
    for i in range(1, N + 1, 2):
        result += i
    print(result)
