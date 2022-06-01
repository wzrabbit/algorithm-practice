n = int(input())
cute = 0

for i in range(n):
    if int(input()) == 1:
        cute += 1
    else:
        cute -= 1

if cute > 0:
    print('Junhee is cute!')
else:
    print('Junhee is not cute!')
