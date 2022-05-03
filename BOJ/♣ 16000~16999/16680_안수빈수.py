import sys
input = sys.stdin.readline
current = ''
changed = ''


def is_ansubinsu():
    result = 0
    string = str(changed - current)
    for i in range(len(string)):
        result += int(string[i])

    return result % 2 != 0


t = int(input())
for _ in range(t):
    current = int(input())
    changed = current

    while not is_ansubinsu():
        changed *= 10

    print(changed - current)
