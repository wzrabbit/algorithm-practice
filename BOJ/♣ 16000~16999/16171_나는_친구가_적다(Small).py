raw = input()
word = input()
generated = ""

for i in range(len(raw)):
    if raw[i] not in "1234567890":
        generated += raw[i]

if word in generated:
    print(1)
else:
    print(0)
