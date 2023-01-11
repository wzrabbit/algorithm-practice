N = int(input())
words = input().split()
same_letter = words[0][0]
success = True

for word in words:
    if word[0] != same_letter or word[-1] != same_letter:
        success = False
        break

if success:
    print(1)
else:
    print(0)
