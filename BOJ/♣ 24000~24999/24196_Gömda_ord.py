S = input()
index = 0

while index < len(S):
    print(S[index], end = '')
    index += ord(S[index]) - 64
