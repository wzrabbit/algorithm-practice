input()

problem_left_count = 0

while True:
    cur = input()

    if cur == "고무오리 디버깅 끝":
        break

    if cur == "문제":
        problem_left_count += 1
    elif problem_left_count > 0:
        problem_left_count -= 1
    else:
        problem_left_count += 2

if problem_left_count == 0:
    print("고무오리야 사랑해")
else:
    print("힝구")
