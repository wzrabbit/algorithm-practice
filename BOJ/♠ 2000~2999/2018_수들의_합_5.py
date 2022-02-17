num = int(input())
start = 1
end = 1
total = 1
match = 0

while (end <= num):
    if (num == total):
        match += 1
        end += 1
        total += end
    elif (num < total):
        total -= start
        start += 1
    else:
        end += 1
        total += end

print(match)
