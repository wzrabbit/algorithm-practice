N = int(input())
arr = list(map(int, input().split()))

if len(set(arr)) == N:
    print(1)
else:
    print(0)
