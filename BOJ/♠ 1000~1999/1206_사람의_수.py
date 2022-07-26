def check(avg, ans):
    for i in range(ans * 10 + 1):
        cur = i * 1000 // ans
        if cur == avg:
            return True

    return False


N = int(input())
num = []

for _ in range(N):
    num.append(int(input().replace('.', '')))

for i in range(1, 1001):
    success = True

    for j in range(N):
        if not check(num[j], i):
            success = False
            break

    if success:
        print(i)
        break
