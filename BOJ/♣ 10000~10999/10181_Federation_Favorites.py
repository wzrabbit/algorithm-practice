while True:
    N = int(input())
    divisors = set()
    i = 1

    if N == -1:
        break

    while i * i <= N:
        if N % i == 0:
            divisors.add(i)
            divisors.add(N // i)
        
        i += 1
    
    divisors.remove(N)
    divisors = sorted(list(divisors))

    if sum(divisors) == N:
        print(f'{N} = {" + ".join(list(map(str, divisors)))}')
    else:
        print(f'{N} is NOT perfect.')
