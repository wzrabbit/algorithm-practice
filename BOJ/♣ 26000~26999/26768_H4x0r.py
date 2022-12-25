import sys
input = sys.stdin.readline
print = sys.stdout.write

text = input()
before = ['a', 'e', 'i', 'o', 's']
after = ['4', '3', '1', '0', '5']

for i in range(5):
    text = text.replace(before[i], after[i])

print(text)
