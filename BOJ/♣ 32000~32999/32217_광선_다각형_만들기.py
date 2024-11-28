N = int(input())
arr = list(map(int, input().split()))
total = (N - 1) * 90

answer = total - sum(arr)
answer *= 2

print(answer)
