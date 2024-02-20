S = input()
divisor = 1

for i in range(2, 101):
    if i * i > len(S):
        break

    if len(S) % i == 0:
        divisor = i

for i in range(divisor):
    for j in range(i, len(S), divisor):
        print(S[j], end="")
