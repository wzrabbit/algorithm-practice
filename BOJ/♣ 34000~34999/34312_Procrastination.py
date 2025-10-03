import sys
input = sys.stdin.readline

N, M = map(int, input().split())
tasks = [tuple(map(int, input().split())) for _ in range(N)]
tasks.sort(key=lambda x: (x[0], -x[1]))
total_grade = 0

for (time, grade) in tasks:
    if M < time:
        break

    M -= time
    total_grade += grade

print(total_grade)
