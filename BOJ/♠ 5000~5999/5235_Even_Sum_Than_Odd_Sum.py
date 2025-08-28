T = int(input())

for _ in range(T):
    arr = list(map(int, input().split()))[1:]
    even_sum = 0
    odd_sum = 0

    for cur in arr:
        if cur % 2 == 0:
            even_sum += cur
        else:
            odd_sum += cur

    if even_sum > odd_sum:
        print('EVEN')
    elif even_sum < odd_sum:
        print('ODD')
    else:
        print('TIE')
