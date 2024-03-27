C = input()
S = input()
index = 0
answer = 0

for i in S:
    if i == C[index]:
        index += 1

        if index == len(C):
            answer += 1
            index = 0

print(answer)
