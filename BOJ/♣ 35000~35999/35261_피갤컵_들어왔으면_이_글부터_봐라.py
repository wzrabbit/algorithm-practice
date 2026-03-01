N = int(input())
S = input()
answer = 5
eagle = 'eagle'

for i in range(N - 4):
    cur = 5
    for j in range(5):
        if S[i + j] == eagle[j]:
            cur -= 1
    answer = min(cur, answer)

print(answer)
