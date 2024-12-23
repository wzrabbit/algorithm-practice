N = int(input())
encrypted = sorted(list(map(int, input().split())))
sentence = sorted(input())
success = True

for i in range(N):
    if "a" <= sentence[i] <= "z" and encrypted[i] != ord(sentence[i]) - ord("a") + 27:
        success = False
        break

    if "A" <= sentence[i] <= "Z" and encrypted[i] != ord(sentence[i]) - ord("A") + 1:
        success = False
        break

    if sentence[i] == " " and encrypted[i] != 0:
        success = False
        break

if success:
    print("y")
else:
    print("n")
