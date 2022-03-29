dwarf = []
for i in range(9):
    dwarf.append(int(input()))
sum_ = sum(dwarf)

for i in range(9):
    found = False
    for j in range(i + 1, 9):
        if sum_ - dwarf[i] - dwarf[j] == 100:
            dwarf[i] = -1
            dwarf[j] = -1
            found = True
            break
    if found:
        break

dwarf.sort()
for i in range(2, 9):
    print(dwarf[i])
