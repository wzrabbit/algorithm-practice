original = "SciComLove"
modified = input()
diff_count = 0

for i in range(10):
    if original[i] != modified[i]:
        diff_count += 1

print(diff_count)
