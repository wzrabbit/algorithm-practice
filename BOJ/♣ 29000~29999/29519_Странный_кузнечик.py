N = int(input())
arr = list(map(int, input().split()))
pos = 0

while True:
    pos += pos + 1

    if pos == N - 1:
        break

    if pos >= N or arr[pos] == 0:
        print("No")
        exit(0)

print("Yes")
