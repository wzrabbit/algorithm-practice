string, length = map(int, input().split())
length = min(string * len(str(string)), length)
string = str(string)

print(string * (length // len(string)) + string[:length % len(string)])
