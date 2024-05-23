HH, MM, SS = map(int, input().split())
D = int(input())
SS += D

MM += SS // 60
SS %= 60

HH += MM // 60
MM %= 60

HH %= 24

print(HH, MM, SS)
