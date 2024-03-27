S = input()
count = 0

for i in "aeiou":
    count += S.count(i)

print(count, end=" ")

count += S.count("y")

print(count)
