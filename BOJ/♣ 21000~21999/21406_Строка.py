N = int(input())
res = ''

for num in range(1, N + 1):
    if str(num) not in res:
        res += str(num)
        
print(res)