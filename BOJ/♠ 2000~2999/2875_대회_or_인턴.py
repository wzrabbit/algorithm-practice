F, M, K = map(int, input().split())

while K > 0:
    if F > M * 2:
        F -= 1
    else:
        M -= 1
    K -= 1

print(min(F // 2, M))
