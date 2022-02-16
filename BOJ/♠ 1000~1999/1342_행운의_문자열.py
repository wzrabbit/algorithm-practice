data = input().rstrip()
goal = len(data)
count = 0
elements = {}
for i in range(goal):
    if data[i] in elements:
        elements[data[i]] += 1
    else:
        elements[data[i]] = 1
elements = list(elements.values())

def backtracking(current, length):
    global count
    elements[current] -= 1
    if length == goal:
        count += 1
        elements[current] += 1
        return
    for i in range(len(elements)):
        if elements[i] > 0 and i != current:
            backtracking(i, length + 1)
    elements[current] += 1

for k in range(len(elements)):
    backtracking(k, 1)
print(count)