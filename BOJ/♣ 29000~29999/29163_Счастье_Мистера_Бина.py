N = int(input())
arr = list(map(int, input().split()))

even_count = 0

for i in range(N):
    if arr[i] % 2 == 0:
        even_count += 1

if even_count * 2 > N:
    print('Happy')
else:
    print('Sad')
