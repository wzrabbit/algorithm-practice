n = int(input())
arr = list(map(int, input().split()))
a = arr[0] - 1
b = arr[n - 1] - 1
pop = len(arr) - 3

for i in range(pop):
    if a < b:
        a, b = b, a
    a -= 1

print(max(a, b))
