N, M, X, Y = map(int, input().split())
hanyang_score = int(input().split()[1])
other_scores = []

for _ in range(N - 1):
    student_no, score = map(int, input().split())

    if student_no // 1000000 != 2024:
        continue

    deducted_score = X - score
    other_scores.append(score + max(Y - deducted_score, 0))

other_scores.append(0)
other_scores.sort(reverse=True)
index = min(len(other_scores), M) - 1

need_score = max(0, other_scores[index] - hanyang_score)

if need_score > Y:
    print("NO")
else:
    print("YES")
    print(need_score)
