N, K = map(int, input().split())
S = input()
x = 0
y = 0

for cur in S * min(K, N):
    if cur == "U":
        y += 1
    elif cur == "D":
        y -= 1
    elif cur == "L":
        x -= 1
    else:
        x += 1

    if x == 0 and y == 0:
        print("YES")
        exit(0)

print("NO")
