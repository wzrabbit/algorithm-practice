data = list('0123456789ABCDEF')
string = input()
result = 0

for i in range(len(string)):
    result += 16 ** (len(string) - i - 1) * data.index(string[i])

print(result)
