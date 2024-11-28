wrong_count = [0] * 26
penalty = 0
solve_count = 0

while True:
    line = input()

    if line == "-1":
        print(solve_count, penalty)
        break

    time, problem_no, verdict = line.split()
    time = int(time)

    if verdict == "wrong":
        wrong_count[ord(problem_no) - ord('A')] += 1
        continue

    penalty += time + wrong_count[ord(problem_no) - ord('A')] * 20
    solve_count += 1
