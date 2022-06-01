dwarf = []
for _ in range(9):
    dwarf.append(int(input()))
sum_ = sum(dwarf)
found = False

for i in range(8):
    for j in range(i + 1, 9):
        if sum_ - dwarf[i] - dwarf[j] == 100:
            dwarf[i], dwarf[j] = -1, -1
            found = True
            break

    if found:
        break

for i in range(9):
    if dwarf[i] != -1:
        print(dwarf[i])
