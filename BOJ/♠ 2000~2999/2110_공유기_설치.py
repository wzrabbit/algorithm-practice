import sys
input = sys.stdin.readline


def is_possible(X):
    prev = -10 ** 10
    placed = 0

    for i in range(house):
        if arr[i] - prev >= X:
            prev = arr[i]
            placed += 1

    if placed >= need:
        return True
    else:
        return False


house, need = map(int, input().split())
arr = []

for _ in range(house):
    arr.append(int(input()))
arr.sort()

start = 0
end = 10 ** 10
mid = ''
while start < end:
    mid = (start + end) // 2
    if (start + end) % 2 != 0:
        mid += 1

    if is_possible(mid):
        start = mid
    else:
        end = mid - 1

print(end)
