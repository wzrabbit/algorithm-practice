Q = int(input())

for _ in range(Q):
    S = input()
    answer = 0

    for i in range(len(S)):
        if S[i:i+3] == 'WOW':
            answer += 1

    print(answer)
