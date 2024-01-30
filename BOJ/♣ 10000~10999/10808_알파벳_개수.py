S = input()
answer = [0] * 26

for i in S:
    answer[ord(i) - 97] += 1

print(*answer)
