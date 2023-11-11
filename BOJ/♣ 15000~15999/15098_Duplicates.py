words = input().split()
initial_size = len(words)
words_set = set(words)

if len(words_set) == initial_size:
    print("yes")
else:
    print("no")
