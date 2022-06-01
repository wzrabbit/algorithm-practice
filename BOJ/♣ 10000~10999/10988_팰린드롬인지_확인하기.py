text = input()
l = 0
r = len(text) - 1
success = True

while l < r:
    if l != r:
        success = False
        break
    l += 1
    r -= 1

if success:
    print(1)
else:
    print(0)
