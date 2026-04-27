N = int(input())
arr = list(map(int, input().split()))
answer = 0

for cur in arr:
    answer += (cur + 1) // 2

print(answer)
