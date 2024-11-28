R, C = map(int, input().split())

answer = 0

answer += (R - 1) * (C - 1) * 2
answer += (R - 1) * C
answer += R * (C - 1)

print(answer)
