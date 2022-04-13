while True:
    n = int(input())
    if n == 0:
        break

    word = []
    for i in range(n):
        word.append(input())
    word.sort(key=lambda x: x.lower())
    print(word[0])
