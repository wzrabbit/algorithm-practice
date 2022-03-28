import sys
input = sys.stdin.readline
n = int(input())
archer = list(map(int, input().split()))
max_ = 0
current_archer = archer[0]
current_kill = 0

for i in range(1, n):
    if archer[i] < current_archer:
        current_kill += 1
        if current_kill >= max_:
            max_ = current_kill
    else:
        current_archer = archer[i]
        current_kill = 0

print(max_)
