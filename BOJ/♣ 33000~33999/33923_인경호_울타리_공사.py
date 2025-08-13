R, C = map(int, input().split())
R -= 1
C -= 1

if R != C:
    print(min(R, C) ** 2)
    exit()

answer = 0

for i in range(1, R):
    answer = max(answer, R ** 2 - i * (R - i) * 2)

print(answer)
