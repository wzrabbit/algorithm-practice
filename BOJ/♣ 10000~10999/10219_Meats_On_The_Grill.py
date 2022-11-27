T = int(input())
for _ in range(T):
    R, C = map(int, input().split())
    for __ in range(R):
        print(input()[::-1])