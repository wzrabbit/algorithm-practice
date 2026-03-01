M, H = map(int, input().split())
N = int(input())
answer = 0

for _ in range(N):
    C, B = map(int, input().split())

    if C * M >= B * H:
        answer += C * M
    else:
        answer += B * H

print(answer)
