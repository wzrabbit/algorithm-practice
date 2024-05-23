N = int(input())
K = input()
odd_count = 0
even_count = 0

for i in K:
    if int(i) % 2 == 0:
        even_count += 1
    else:
        odd_count += 1
        
if even_count > odd_count:
    print(0)
elif even_count < odd_count:
    print(1)
else:
    print(-1)
