import sys
cases = int(sys.stdin.readline())
num = []
total = 0
for _ in range(cases):
    num.append(int(sys.stdin.readline()))
num.sort()

index = 0
while len(num) > index and num[index] <= 0:
    if len(num) > index + 1:
        if max(num[index], num[index + 1]) <= 0:
            total += num[index] * num[index + 1]
            index += 2
        else:
            total += num[index]
            break
    else:
        total += num[index]
        break

index = len(num) - 1
while index >= 0 and num[index] > 0:
    if index > 0:
        if min(num[index], num[index - 1]) > 1:
            total += num[index] * num[index - 1]
            index -= 2
        elif min(num[index], num[index - 1]) >= 0:
            total += num[index] + num[index - 1]
            index -= 2
        else:
            total += num[index]
            break
    else:
        total += num[index]
        break

print(total)
