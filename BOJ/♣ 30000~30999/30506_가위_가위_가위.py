import sys

input = sys.stdin.readline
print = sys.stdout.write
flush = sys.stdout.flush

score = int(input())
answer = ""

for i in range(100):
    print("? " + "2" * i + "0" + "2" * (100 - i - 1) + "\n")
    flush()

    new_score = int(input())

    if new_score == score:
        answer += "0"
    elif new_score < score:
        answer += "5"
    else:
        answer += "2"

print("! " + answer + "\n")
flush()
