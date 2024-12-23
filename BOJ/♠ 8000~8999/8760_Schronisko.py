T = int(input())

for _ in range(T):
    W, H = map(int, input().split())

    print(W * H // 2)
