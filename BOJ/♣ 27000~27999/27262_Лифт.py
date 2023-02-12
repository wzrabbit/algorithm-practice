n, k, a, b = map(int, input().split())
elevator_time = (n + k - 2) * b
stair_time = (n - 1) * a

print(elevator_time, stair_time)
