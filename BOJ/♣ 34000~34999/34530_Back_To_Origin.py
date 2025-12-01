N = int(input())
state = N
answer = 1

while state != 0:
    state = (state + N) % 360
    answer += 1

print(answer)
