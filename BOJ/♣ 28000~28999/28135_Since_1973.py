N = int(input())
cur = 0
answer = 0

while True:
    cur += 1
    answer += 1

    if N == cur:
        print(answer)
        break

    if '50' in str(cur):
        answer += 1
