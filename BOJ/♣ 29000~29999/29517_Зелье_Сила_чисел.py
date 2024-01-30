N = int(input())
answer_count = 0

for i in range(1, 65):
    for j in range(0, 65):
        if 2**i * 3**j <= N:
            answer_count += 1

print(answer_count)
