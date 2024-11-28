import sys
input = sys.stdin.readline
debug = print
print = sys.stdout.write
MOD = 1000000007

T = int(input())
vowels = ["a", "e", "i",  "o", "u"]

for _ in range(T):
    S = input().strip()
    impossible = True

    for i in range(5):
        if vowels[i] in S:
            impossible = False
            break

    if impossible:
        print('-1\n')
        continue

    values = []
    before_vowel = -1

    for i in range(len(S)):
        if S[i] in vowels:
            if before_vowel != -1:
                values.append(i - before_vowel)
            before_vowel = i

    answer = 1

    for i in range(len(values)):
        answer = (answer * values[i]) % MOD
    
    print(f'{answer}\n')
