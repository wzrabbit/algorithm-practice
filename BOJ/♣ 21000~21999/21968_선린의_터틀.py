n = int(input())
binary = bin(n)[2:]
answer = 0
mul = 1

for i in reversed(range(len(binary))):
    if binary[i] == '1':
        answer += mul
    mul *= 3

print(answer)
