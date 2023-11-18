S = input()
korea = "KOREA"
index = 0
answer = 0

for i in S:
    if i == korea[index]:
        index = (index + 1) % 5
        answer += 1

print(answer)
