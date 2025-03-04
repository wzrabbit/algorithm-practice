N = int(input())

for _ in range(N):
    A = input()
    B = input()
    diff = 0

    for i in range(len(A)):
        if A[i] != B[i]:
            diff += 1
    
    print(f'Hamming distance is {diff}.')
