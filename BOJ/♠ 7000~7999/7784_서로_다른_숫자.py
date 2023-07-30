from collections import deque

visited = []
prev_index = []
digit = []
N = ''
best = [1, 3]


def compare_answer(digit_count):
    cur_index = 0
    answer = []
    global best

    while True:
        answer.append(str(digit[cur_index]))
        if prev_index[cur_index] == -1:
            break

        cur_index = prev_index[cur_index]

    result_number = int(''.join(reversed(answer)))

    if digit_count < best[1]:
        best = [result_number, digit_count]
    elif digit_count == best[1]:
        best[0] = min(best[0], result_number)


def perform(a, b):
    global prev_index
    global digit

    visited = [False] * N
    prev_index = [-1] * N
    digit = [-1] * N
    digit_count = 1 if a == b else 2
    possible_num = [a, b]
    q = deque()

    for i in possible_num:
        if i != 0:
            visited[i % N] = True

            digit[i % N] = i
            q.append(i % N)

    while len(q) > 0:
        cur = q.popleft()

        if cur == 0:

            compare_answer(digit_count)
            return

        for x in possible_num:
            nxt = (cur * 10 + x) % N
            if not visited[nxt]:
                visited[nxt] = True
                prev_index[nxt] = cur
                digit[nxt] = x
                q.append(nxt)


while True:
    N = int(input())
    best = [1, 3]

    if N == 0:
        break

    for i in range(10):
        for j in range(i, 10):
            perform(i, j)

    print(best[0])
