import sys
print = sys.stdout.write


def get_word(X):
    if X < 0:
        X += 130

    result = [''] * 5

    for i in range(5):
        result[i] = chr(97 + (X // 5) % 26)

    for i in range(X % 5):
        result[i] = chr(97 + (X // 5 + 1) % 26)

    return ''.join(result)


def print_ladder(N):
    i = 0
    cnt = 0
    end = 125

    while True:
        for j in range(end - 125, end + 1):
            cnt += 1
            print(get_word(i) + get_word(j) + '\n')
            if cnt == N:
                return

        for _ in range(2):
            i += 1
            cnt += 1
            print(get_word(i) + get_word(end) + '\n')
            if cnt == N:
                return

        end = (end - 5) % 130


N = int(input())
print_ladder(N)
