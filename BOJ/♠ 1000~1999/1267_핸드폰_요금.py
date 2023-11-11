N = int(input())
arr = list(map(int, input().split()))
Y = 0
M = 0

for i in range(N):
    Y += arr[i] // 30 * 10 + 10
    M += arr[i] // 60 * 15 + 15

if Y > M:
    print(f"M {M}")
elif Y < M:
    print(f"Y {Y}")
else:
    print(f"Y M {Y}")
