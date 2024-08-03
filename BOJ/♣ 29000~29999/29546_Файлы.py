N = int(input())
files = []

for i in range(N):
    files.append(input())

Q = int(input())

for _ in range(Q):
    start, end = map(int, input().split())
    start -= 1
    end -= 1

    for i in range(start, end + 1):
        print(files[i])
