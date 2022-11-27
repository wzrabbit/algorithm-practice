N = int(input())
arr = list(map(int, input().split()))
hit_count = 0

for i in range(N):
    if arr[i] != i + 1:
        hit_count += 1

print(hit_count)
