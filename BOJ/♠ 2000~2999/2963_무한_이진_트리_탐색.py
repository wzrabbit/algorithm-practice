query = input()
value = 1
cnt = 1

for i in range(len(query)):
    if query[i] == "L":
        value *= 2
    elif query[i] == "R":
        value = value * 2 + cnt
    elif query[i] == "*":
        value = value * 5 + cnt
        cnt *= 3

print(value)
