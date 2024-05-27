N = int(input())
seconds = 8
power = 1

while N > 0:
    seconds += 1
    N -= power
    power *= 2

seconds += 1

print(seconds)
