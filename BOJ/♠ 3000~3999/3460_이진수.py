T = int(input())

for _ in range(T):
    N = int(input())
    bin_N = bin(N)[2:]

    for i in reversed(range(len(bin_N))):
        if bin_N[i] == '1':
            print(len(bin_N) - i - 1, end=' ')
    
    print()