N = int(input())
arr = []
missing = []

for _ in range(N):
    arr.append(int(input()))
    
max_number = max(arr)

for i in range(1, max_number + 1):
    if i not in arr:
        missing.append(i)
        
if len(missing) > 0:
    print(*missing, sep="\n")
else:
    print('good job')
