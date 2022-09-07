N, P = map(int, input().split())
score = list(map(int, input().split()))
max_student = ''
max_score = -1

for _ in range(P):
    data = input().split()
    cur_score = 0

    for i in range(1, N + 1):
        if data[i] == 'O':
            cur_score += score[i - 1]

    if cur_score > max_score or (cur_score == max_score and int(data[0]) < max_student):
        max_student = int(data[0])
        max_score = cur_score

print(max_student, max_score)
