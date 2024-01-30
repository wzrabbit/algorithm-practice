answer = None
exp = None

while True:
    cur = input()

    if cur in ("+", "-", "*", "/"):
        exp = cur
        continue

    if cur == "=":
        print(answer)
        break

    if answer == None:
        answer = int(cur)
        continue

    if exp == "+":
        answer += int(cur)
        continue

    if exp == "-":
        answer -= int(cur)
        continue

    if exp == "*":
        answer *= int(cur)
        continue

    answer //= int(cur)
    continue
