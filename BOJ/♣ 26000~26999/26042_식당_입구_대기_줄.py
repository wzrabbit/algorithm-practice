import sys
input = sys.stdin.readline

Q = int(input())
best_student_count = 0
best_student_no = 0
cur_student_count = 0

for _ in range(Q):
    query = list(map(int, input().split()))

    if query[0] == 1:
        cur_student_count += 1
    else:
        cur_student_count -= 1

    if cur_student_count > best_student_count or (cur_student_count == best_student_count and query[1] < best_student_no):
        best_student_count = cur_student_count
        best_student_no = query[1]

print(best_student_count, best_student_no)
