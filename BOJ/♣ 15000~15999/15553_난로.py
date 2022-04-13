import sys
input = sys.stdin.readline

friend, fire = map(int, input().split())
before = int(input())
interval = []
time = friend

for _ in range(friend - 1):
    current = int(input())
    interval.append(current - before - 1)
    before = current

interval.sort()

index = 0
while fire < friend:
    time += interval[index]
    fire += 1
    index += 1
print(time)
