def get_answer(num):
    if num == 1:
        return 'Deficient'

    i = 2
    total = 0

    while i * i <= num:
        if num % i == 0:
            if i * i == num:
                total += i
            else:
                total += i + num // i
        
        i += 1

    total += 1

    if total > num:
        return 'Abundant'

    if total < num:
        return 'Deficient'

    return 'Perfect'

T = int(input())
arr = list(map(int, input().split()))

for i in range(T):
    print(get_answer(arr[i]))
