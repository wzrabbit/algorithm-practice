import sys
input = sys.stdin.readline

num = int(input())
tree = list(map(int, input().split()))
sum_ = sum(tree)

if sum_ % 3 != 0:
    print("NO")
else:
    twoNeed = sum_ // 3
    result = "NO"
    for i in range(num):
        twoNeed -= tree[i] // 2
        if twoNeed <= 0:
            result = "YES"
            break
    print(result)
