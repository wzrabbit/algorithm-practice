N, M = map(int, input().split())
answer = [['+'] * M for _ in range(N)]
index = 0

for i in range(M):
    morning, evening = map(int, input().split())

    if morning + evening > N:
        print("NO")
        exit()

    absent_count = max(0, N - morning - evening)
    
    for j in range(index, min(N, index + absent_count)):
        answer[j][i] = "X"
    index += absent_count
    
    for j in range(N):
        if evening <= 0:
            break

        if answer[j][i] == "+":
            answer[j][i] = "-"
            evening -= 1

if index < N:
    print("NO")
    exit()

print("YES")
for i in range(N):
    print("".join(answer[i]))
