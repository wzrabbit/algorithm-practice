import sys
input = sys.stdin.readline

N = list(map(int, input().split()))[1]
dot_x = []
dot_y = []
for _ in range(N):
    X, Y = map(int, input().split())
    dot_x.append(X)
    dot_y.append(Y)

dot_x.sort()
dot_y.sort()
ans_x = dot_x[N // 2]
ans_y = dot_y[N // 2]

dist = 0
for i in range(N):
    dist += abs(ans_x - dot_x[i]) + abs(ans_y - dot_y[i])
print(dist)
