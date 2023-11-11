N = int(input())
sentence = input()

if N <= 25:
    print(sentence)
    exit()

if "." not in sentence[11 : N - 12]:
    print(sentence[:11] + "..." + sentence[N - 11 :])
    exit()

print(sentence[:9] + "......" + sentence[N - 10 :])
